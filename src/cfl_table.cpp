#include "cfl_table.h"
#include "cfl_lock.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Table_Row.H>

#define TABLE_CLASS(table)                                                                         \
    struct table##_Derived : public table {                                                        \
        void *ev_data_ = NULL;                                                                     \
        void *draw_data_ = NULL;                                                                   \
        void *draw_cell_data_ = NULL;                                                              \
                                                                                                   \
        typedef int (*handler)(Fl_Widget *, int, void *data);                                      \
        handler inner_handler = NULL;                                                              \
        typedef void (*drawer)(Fl_Widget *, void *data);                                           \
        drawer inner_drawer = NULL;                                                                \
        typedef void (*cell_drawer)(Fl_Widget *, int, int, int, int, int, int, int, void *data);   \
        cell_drawer inner_cell_drawer = NULL;                                                      \
        typedef void (*deleter_fp)(void *);                                                        \
        deleter_fp deleter = NULL;                                                                 \
        table##_Derived(int x, int y, int w, int h, const char *title = 0)                         \
            : table(x, y, w, h, title) {                                                           \
        }                                                                                          \
        operator table *() {                                                                       \
            return (table *)this;                                                                  \
        }                                                                                          \
        void widget_resize(int x, int y, int w, int h) {                                           \
            Fl_Widget::resize(x, y, w, h);                                                         \
            redraw();                                                                              \
        }                                                                                          \
        void set_handler(handler h) {                                                              \
            inner_handler = h;                                                                     \
        }                                                                                          \
        void set_handler_data(void *data) {                                                        \
            ev_data_ = data;                                                                       \
        }                                                                                          \
        int handle(int event) override {                                                           \
            int local = 0;                                                                         \
            if (inner_handler) {                                                                   \
                local = inner_handler(this, event, ev_data_);                                      \
                if (local == 0)                                                                    \
                    return table::handle(event);                                                   \
                else                                                                               \
                    return table::handle(event) | local;                                           \
            } else {                                                                               \
                return table::handle(event);                                                       \
            }                                                                                      \
        }                                                                                          \
        void set_drawer(drawer h) {                                                                \
            inner_drawer = h;                                                                      \
        }                                                                                          \
        void set_drawer_data(void *data) {                                                         \
            draw_data_ = data;                                                                     \
        }                                                                                          \
        void set_cell_drawer(cell_drawer h) {                                                      \
            inner_cell_drawer = h;                                                                 \
        }                                                                                          \
        void set_cell_drawer_data(void *data) {                                                    \
            draw_cell_data_ = data;                                                                \
        }                                                                                          \
        void draw() override {                                                                     \
            table::draw();                                                                         \
            if (inner_drawer)                                                                      \
                inner_drawer(this, draw_data_);                                                    \
            else {                                                                                 \
            }                                                                                      \
        }                                                                                          \
        void draw_cell(TableContext context, int R, int C, int X, int Y, int W, int H) override {  \
            table::draw_cell(context, R, C, X, Y, W, H);                                           \
            if (inner_cell_drawer)                                                                 \
                inner_cell_drawer(this, context, R, C, X, Y, W, H, draw_cell_data_);               \
            else {                                                                                 \
            }                                                                                      \
        }                                                                                          \
        void *scrollbar() const {                                                                  \
            return (void *)table::vscrollbar;                                                      \
        }                                                                                          \
        void *hscrollbar() const {                                                                 \
            return (void *)table::hscrollbar;                                                      \
        }                                                                                          \
        ~table##_Derived() {                                                                       \
            if (ev_data_)                                                                          \
                deleter(ev_data_);                                                                 \
            ev_data_ = NULL;                                                                       \
            inner_handler = NULL;                                                                  \
            if (draw_data_)                                                                        \
                deleter(draw_data_);                                                               \
            draw_data_ = NULL;                                                                     \
            inner_drawer = NULL;                                                                   \
            if (user_data())                                                                       \
                deleter(user_data());                                                              \
            user_data(NULL);                                                                       \
            callback((void (*)(Fl_Widget *, void *))NULL);                                         \
        }                                                                                          \
    };

#define TABLE_DEFINE(table)                                                                        \
    void table##_set_table_box(table *self, int val) {                                             \
        LOCK(self->table_box((Fl_Boxtype)val);)                                                    \
    }                                                                                              \
    int table##_table_box(table *self) {                                                           \
        LOCK(auto ret = self->table_box(););                                                       \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_rows(table *self, int val) {                                                  \
        LOCK(self->rows(val);)                                                                     \
    }                                                                                              \
    int table##_rows(table *self) {                                                                \
        LOCK(auto ret = self->rows(););                                                            \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_cols(table *self, int val) {                                                  \
        LOCK(self->cols(val);)                                                                     \
    }                                                                                              \
    int table##_cols(table *self) {                                                                \
        LOCK(auto ret = self->cols(););                                                            \
        return ret;                                                                                \
    }                                                                                              \
    void table##_visible_cells(table *self, int *r1, int *r2, int *c1, int *c2) {                  \
        LOCK(self->visible_cells(*r1, *r2, *c1, *c2);)                                             \
    }                                                                                              \
    int table##_is_interactive_resize(table *self) {                                               \
        LOCK(auto ret = self->is_interactive_resize(););                                           \
        return ret;                                                                                \
    }                                                                                              \
    int table##_row_resize(table *self) {                                                          \
        LOCK(auto ret = self->row_resize(););                                                      \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_row_resize(table *self, int flag) {                                           \
        LOCK(self->row_resize(flag);)                                                              \
    }                                                                                              \
    int table##_col_resize(table *self) {                                                          \
        LOCK(auto ret = self->col_resize(););                                                      \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_col_resize(table *self, int flag) {                                           \
        LOCK(self->col_resize(flag);)                                                              \
    }                                                                                              \
    int table##_col_resize_min(table *self) {                                                      \
        LOCK(auto ret = self->col_resize_min(););                                                  \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_col_resize_min(table *self, int val) {                                        \
        LOCK(self->col_resize_min(val);)                                                           \
    }                                                                                              \
    int table##_row_resize_min(table *self) {                                                      \
        LOCK(auto ret = self->row_resize_min(););                                                  \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_row_resize_min(table *self, int val) {                                        \
        LOCK(self->row_resize_min(val);)                                                           \
    }                                                                                              \
    int table##_row_header(table *self) {                                                          \
        LOCK(auto ret = self->row_header(););                                                      \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_row_header(table *self, int flag) {                                           \
        LOCK(self->row_header(flag);)                                                              \
    }                                                                                              \
    int table##_col_header(table *self) {                                                          \
        LOCK(auto ret = self->col_header(););                                                      \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_col_header(table *self, int flag) {                                           \
        LOCK(self->col_header(flag);)                                                              \
    }                                                                                              \
    void table##_set_col_header_height(table *self, int height) {                                  \
        LOCK(self->col_header_height(height);)                                                     \
    }                                                                                              \
    int table##_col_header_height(table *self) {                                                   \
        LOCK(auto ret = self->col_header_height(););                                               \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_row_header_width(table *self, int width) {                                    \
        LOCK(self->row_header_width(width);)                                                       \
    }                                                                                              \
    int table##_row_header_width(table *self) {                                                    \
        LOCK(auto ret = self->row_header_width(););                                                \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_row_header_color(table *self, unsigned int val) {                             \
        LOCK(self->row_header_color(val);)                                                         \
    }                                                                                              \
    unsigned int table##_row_header_color(table *self) {                                           \
        LOCK(auto ret = self->row_header_color(););                                                \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_col_header_color(table *self, unsigned int val) {                             \
        LOCK(self->col_header_color(val);)                                                         \
    }                                                                                              \
    unsigned int table##_col_header_color(table *self) {                                           \
        LOCK(auto ret = self->col_header_color(););                                                \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_row_height(table *self, int row, int height) {                                \
        LOCK(self->row_height(row, height);)                                                       \
    }                                                                                              \
    int table##_row_height(table *self, int row) {                                                 \
        LOCK(auto ret = self->row_height(row););                                                   \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_col_width(table *self, int col, int width) {                                  \
        LOCK(self->col_width(col, width);)                                                         \
    }                                                                                              \
    int table##_col_width(table *self, int col) {                                                  \
        LOCK(auto ret = self->col_width(col););                                                    \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_row_height_all(table *self, int height) {                                     \
        LOCK(self->row_height_all(height);)                                                        \
    }                                                                                              \
    void table##_set_col_width_all(table *self, int width) {                                       \
        LOCK(self->col_width_all(width);)                                                          \
    }                                                                                              \
    void table##_set_row_position(table *self, int row) {                                          \
        LOCK(self->row_position(row);)                                                             \
    }                                                                                              \
    void table##_set_col_position(table *self, int col) {                                          \
        LOCK(self->col_position(col);)                                                             \
    }                                                                                              \
    int table##_row_position(table *self) {                                                        \
        LOCK(auto ret = self->row_position(););                                                    \
        return ret;                                                                                \
    }                                                                                              \
    int table##_col_position(table *self) {                                                        \
        LOCK(auto ret = self->col_position(););                                                    \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_top_row(table *self, int row) {                                               \
        LOCK(self->top_row(row);)                                                                  \
    }                                                                                              \
    int table##_top_row(table *self) {                                                             \
        LOCK(auto ret = self->top_row(););                                                         \
        return ret;                                                                                \
    }                                                                                              \
    int table##_is_selected(table *self, int r, int c) {                                           \
        LOCK(auto ret = self->is_selected(r, c););                                                 \
        return ret;                                                                                \
    }                                                                                              \
    void table##_get_selection(table *self, int *row_top, int *col_left, int *row_bot,             \
                               int *col_right) {                                                   \
        LOCK(self->get_selection(*row_top, *col_left, *row_bot, *col_right);)                      \
    }                                                                                              \
    void table##_set_selection(table *self, int row_top, int col_left, int row_bot,                \
                               int col_right) {                                                    \
        LOCK(self->set_selection(row_top, col_left, row_bot, col_right);)                          \
    }                                                                                              \
    int table##_move_cursor_with_shiftselect(table *self, int R, int C, int shiftselect) {         \
        LOCK(auto ret = self->move_cursor(R, C, shiftselect););                                    \
        return ret;                                                                                \
    }                                                                                              \
    int table##_move_cursor(table *self, int R, int C) {                                           \
        LOCK(auto ret = self->move_cursor(R, C););                                                 \
        return ret;                                                                                \
    }                                                                                              \
    int table##_scrollbar_size(const table *self) {                                                \
        LOCK(auto ret = self->scrollbar_size(););                                                  \
        return ret;                                                                                \
    }                                                                                              \
    void table##_set_scrollbar_size(table *self, int newSize) {                                    \
        LOCK(self->scrollbar_size(newSize);)                                                       \
    }                                                                                              \
    void table##_set_tab_cell_nav(table *self, int val) {                                          \
        LOCK(self->tab_cell_nav(val);)                                                             \
    }                                                                                              \
    int table##_tab_cell_nav(const table *self) {                                                  \
        LOCK(auto ret = self->tab_cell_nav(););                                                    \
        return ret;                                                                                \
    }                                                                                              \
    void table##_draw_cell(table *self,                                                            \
                           void (*cb)(Fl_Widget *, int, int, int, int, int, int, int, void *),     \
                           void *data) {                                                           \
        LOCK(((table##_Derived *)self)->set_cell_drawer_data(data);                                \
             ((table##_Derived *)self)->set_cell_drawer(cb);)                                      \
    }                                                                                              \
    void *table##_draw_cell_data(const table *self) {                                              \
        LOCK(auto ret = ((table##_Derived *)self)->draw_cell_data_);                               \
        return ret;                                                                                \
    }                                                                                              \
    void table##_draw_cell_data(table *self, void *data) {                                         \
        LOCK(((table##_Derived *)self)->draw_cell_data_ = data)                                    \
    }                                                                                              \
    int table##_callback_col(table *self) {                                                        \
        LOCK(auto ret = self->callback_col(););                                                    \
        return ret;                                                                                \
    }                                                                                              \
    int table##_callback_row(table *self) {                                                        \
        LOCK(auto ret = self->callback_row(););                                                    \
        return ret;                                                                                \
    }                                                                                              \
    int table##_callback_context(table *self) {                                                    \
        LOCK(auto ret = self->callback_context(););                                                \
        return ret;                                                                                \
    }                                                                                              \
    void *table##_scrollbar(const table *self) {                                                   \
        LOCK(auto ret = ((table##_Derived *)self)->scrollbar());                                   \
        return ret;                                                                                \
    }                                                                                              \
    void *table##_hscrollbar(const table *self) {                                                  \
        LOCK(auto ret = ((table##_Derived *)self)->hscrollbar());                                  \
        return ret;                                                                                \
    }

TABLE_CLASS(Fl_Table)

WIDGET_DEFINE(Fl_Table)

GROUP_DEFINE(Fl_Table)

TABLE_DEFINE(Fl_Table)

TABLE_CLASS(Fl_Table_Row)

WIDGET_DEFINE(Fl_Table_Row)

GROUP_DEFINE(Fl_Table_Row)

TABLE_DEFINE(Fl_Table_Row)

int Fl_Table_Row_row_selected(Fl_Table_Row *self, int row) {
    LOCK(auto ret = self->row_selected(row));
    return ret;
}

int Fl_Table_Row_select_row(Fl_Table_Row *self, int row, int flag) {
    LOCK(auto ret = self->select_row(row, flag);)
    return ret;
}

void Fl_Table_Row_select_all_rows(Fl_Table_Row *self, int flag) {
    LOCK(self->select_all_rows(flag);)
}
