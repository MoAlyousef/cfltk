#include "cfl_table.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Table_Row.H>
#include <FL/fl_draw.H>

template <typename Table>
struct Table_Derived : public Widget_Derived<Table> {
    void *draw_cell_data_ = nullptr;

    typedef void (*cell_drawer)(
        Fl_Widget *, int, int, int, int, int, int, int, void *data
    );
    cell_drawer inner_cell_drawer = nullptr;

    Table_Derived(int x, int y, int w, int h, const char *title = nullptr)
        : Widget_Derived<Table>(x, y, w, h, title) {
    }
    operator Table *() {
        return (Table *)this;
    }
    void draw_cell(
        Fl_Table::TableContext context, int R, int C, int X, int Y, int W, int H
    ) override {
        Table::draw_cell(context, R, C, X, Y, W, H);
        if (inner_cell_drawer)
            inner_cell_drawer(this, context, R, C, X, Y, W, H, draw_cell_data_);
        else {
        }
    }
    void *scrollbar() const {
        return (void *)Table::vscrollbar;
    }
    void *hscrollbar() const {
        return (void *)Table::hscrollbar;
    }
    int find_cell(int ctx, int r, int c, int *x, int *y, int *w, int *h) {
        int X = 0, Y = 0, W = 0, H = 0;
        int ret =
            Widget_Derived<Table>::find_cell((Fl_Table::TableContext)ctx, r, c, X, Y, W, H);
        *x = X, *y = Y, *w = W, *h = H;
        return ret;
    }
    int cursor2rowcol(int *r, int *c, int *flag) {
        int R = 0, C = 0;
        auto Flag = (Fl_Table::ResizeFlag)0;
        auto ret  = Widget_Derived<Table>::cursor2rowcol(R, C, Flag);
        *r = R, *c = C, *flag = (int)Flag;
        return (int)ret;
    }
};

#define TABLE_CLASS(table) using table##_Derived = Table_Derived<table>;

#define TABLE_DEFINE(table)                                                    \
    void table##_set_table_box(table *self, int val) {                         \
        LOCK(self->table_box((Fl_Boxtype)val));                                \
    }                                                                          \
    int table##_table_box(table *self) {                                       \
        LOCK(auto ret = self->table_box());                                    \
        return ret;                                                            \
    }                                                                          \
    void table##_set_rows(table *self, int val) {                              \
        LOCK(self->rows(val));                                                 \
    }                                                                          \
    int table##_rows(table *self) {                                            \
        LOCK(auto ret = self->rows());                                         \
        return ret;                                                            \
    }                                                                          \
    void table##_set_cols(table *self, int val) {                              \
        LOCK(self->cols(val));                                                 \
    }                                                                          \
    int table##_cols(table *self) {                                            \
        LOCK(auto ret = self->cols());                                         \
        return ret;                                                            \
    }                                                                          \
    void table##_visible_cells(                                                \
        table *self, int *r1, int *r2, int *c1, int *c2                        \
    ) {                                                                        \
        LOCK(self->visible_cells(*r1, *r2, *c1, *c2));                         \
    }                                                                          \
    int table##_is_interactive_resize(table *self) {                           \
        LOCK(auto ret = self->is_interactive_resize());                        \
        return ret;                                                            \
    }                                                                          \
    int table##_row_resize(table *self) {                                      \
        LOCK(auto ret = self->row_resize());                                   \
        return ret;                                                            \
    }                                                                          \
    void table##_set_row_resize(table *self, int flag) {                       \
        LOCK(self->row_resize(flag));                                          \
    }                                                                          \
    int table##_col_resize(table *self) {                                      \
        LOCK(auto ret = self->col_resize());                                   \
        return ret;                                                            \
    }                                                                          \
    void table##_set_col_resize(table *self, int flag) {                       \
        LOCK(self->col_resize(flag));                                          \
    }                                                                          \
    int table##_col_resize_min(table *self) {                                  \
        LOCK(auto ret = self->col_resize_min());                               \
        return ret;                                                            \
    }                                                                          \
    void table##_set_col_resize_min(table *self, int val) {                    \
        LOCK(self->col_resize_min(val));                                       \
    }                                                                          \
    int table##_row_resize_min(table *self) {                                  \
        LOCK(auto ret = self->row_resize_min());                               \
        return ret;                                                            \
    }                                                                          \
    void table##_set_row_resize_min(table *self, int val) {                    \
        LOCK(self->row_resize_min(val));                                       \
    }                                                                          \
    int table##_row_header(table *self) {                                      \
        LOCK(auto ret = self->row_header());                                   \
        return ret;                                                            \
    }                                                                          \
    void table##_set_row_header(table *self, int flag) {                       \
        LOCK(self->row_header(flag));                                          \
    }                                                                          \
    int table##_col_header(table *self) {                                      \
        LOCK(auto ret = self->col_header());                                   \
        return ret;                                                            \
    }                                                                          \
    void table##_set_col_header(table *self, int flag) {                       \
        LOCK(self->col_header(flag));                                          \
    }                                                                          \
    void table##_set_col_header_height(table *self, int height) {              \
        LOCK(self->col_header_height(height));                                 \
    }                                                                          \
    int table##_col_header_height(table *self) {                               \
        LOCK(auto ret = self->col_header_height());                            \
        return ret;                                                            \
    }                                                                          \
    void table##_set_row_header_width(table *self, int width) {                \
        LOCK(self->row_header_width(width));                                   \
    }                                                                          \
    int table##_row_header_width(table *self) {                                \
        LOCK(auto ret = self->row_header_width());                             \
        return ret;                                                            \
    }                                                                          \
    void table##_set_row_header_color(table *self, unsigned int val) {         \
        LOCK(self->row_header_color(val));                                     \
    }                                                                          \
    unsigned int table##_row_header_color(table *self) {                       \
        LOCK(auto ret = self->row_header_color());                             \
        return ret;                                                            \
    }                                                                          \
    void table##_set_col_header_color(table *self, unsigned int val) {         \
        LOCK(self->col_header_color(val));                                     \
    }                                                                          \
    unsigned int table##_col_header_color(table *self) {                       \
        LOCK(auto ret = self->col_header_color());                             \
        return ret;                                                            \
    }                                                                          \
    void table##_set_row_height(table *self, int row, int height) {            \
        LOCK(self->row_height(row, height));                                   \
    }                                                                          \
    int table##_row_height(table *self, int row) {                             \
        LOCK(auto ret = self->row_height(row));                                \
        return ret;                                                            \
    }                                                                          \
    void table##_set_col_width(table *self, int col, int width) {              \
        LOCK(self->col_width(col, width));                                     \
    }                                                                          \
    int table##_col_width(table *self, int col) {                              \
        LOCK(auto ret = self->col_width(col));                                 \
        return ret;                                                            \
    }                                                                          \
    void table##_set_row_height_all(table *self, int height) {                 \
        LOCK(self->row_height_all(height));                                    \
    }                                                                          \
    void table##_set_col_width_all(table *self, int width) {                   \
        LOCK(self->col_width_all(width));                                      \
    }                                                                          \
    void table##_set_row_position(table *self, int row) {                      \
        LOCK(self->row_position(row));                                         \
    }                                                                          \
    void table##_set_col_position(table *self, int col) {                      \
        LOCK(self->col_position(col));                                         \
    }                                                                          \
    int table##_row_position(table *self) {                                    \
        LOCK(auto ret = self->row_position());                                 \
        return ret;                                                            \
    }                                                                          \
    int table##_col_position(table *self) {                                    \
        LOCK(auto ret = self->col_position());                                 \
        return ret;                                                            \
    }                                                                          \
    void table##_set_top_row(table *self, int row) {                           \
        LOCK(self->top_row(row));                                              \
    }                                                                          \
    int table##_top_row(table *self) {                                         \
        LOCK(auto ret = self->top_row());                                      \
        return ret;                                                            \
    }                                                                          \
    int table##_is_selected(table *self, int r, int c) {                       \
        LOCK(auto ret = self->is_selected(r, c));                              \
        return ret;                                                            \
    }                                                                          \
    void table##_get_selection(                                                \
        table *self, int *row_top, int *col_left, int *row_bot, int *col_right \
    ) {                                                                        \
        LOCK(self->get_selection(*row_top, *col_left, *row_bot, *col_right));  \
    }                                                                          \
    void table##_set_selection(                                                \
        table *self, int row_top, int col_left, int row_bot, int col_right     \
    ) {                                                                        \
        LOCK(self->set_selection(row_top, col_left, row_bot, col_right));      \
    }                                                                          \
    int table##_move_cursor_with_shiftselect(                                  \
        table *self, int R, int C, int shiftselect                             \
    ) {                                                                        \
        LOCK(auto ret = self->move_cursor(R, C, shiftselect));                 \
        return ret;                                                            \
    }                                                                          \
    int table##_move_cursor(table *self, int R, int C) {                       \
        LOCK(auto ret = self->move_cursor(R, C));                              \
        return ret;                                                            \
    }                                                                          \
    int table##_scrollbar_size(const table *self) {                            \
        LOCK(auto ret = self->scrollbar_size());                               \
        return ret;                                                            \
    }                                                                          \
    void table##_set_scrollbar_size(table *self, int newSize) {                \
        LOCK(self->scrollbar_size(newSize));                                   \
    }                                                                          \
    void table##_set_tab_cell_nav(table *self, int val) {                      \
        LOCK(self->tab_cell_nav(val));                                         \
    }                                                                          \
    int table##_tab_cell_nav(const table *self) {                              \
        LOCK(auto ret = self->tab_cell_nav());                                 \
        return ret;                                                            \
    }                                                                          \
    void table##_draw_cell(                                                    \
        table *self,                                                           \
        void (*cb)(Fl_Widget *, int, int, int, int, int, int, int, void *),    \
        void *data                                                             \
    ) {                                                                        \
        LOCK(((table##_Derived *)self)->draw_cell_data_   = data;              \
             ((table##_Derived *)self)->inner_cell_drawer = cb);               \
    }                                                                          \
    void *table##_draw_cell_data(const table *self) {                          \
        LOCK(auto ret = ((table##_Derived *)self)->draw_cell_data_);           \
        return ret;                                                            \
    }                                                                          \
    void table##_draw_cell_data(table *self, void *data) {                     \
        LOCK(((table##_Derived *)self)->draw_cell_data_ = data)                \
    }                                                                          \
    int table##_callback_col(table *self) {                                    \
        LOCK(auto ret = self->callback_col());                                 \
        return ret;                                                            \
    }                                                                          \
    int table##_callback_row(table *self) {                                    \
        LOCK(auto ret = self->callback_row());                                 \
        return ret;                                                            \
    }                                                                          \
    int table##_callback_context(table *self) {                                \
        LOCK(auto ret = self->callback_context());                             \
        return ret;                                                            \
    }                                                                          \
    void *table##_scrollbar(const table *self) {                               \
        LOCK(auto ret = ((table##_Derived *)self)->scrollbar());               \
        return ret;                                                            \
    }                                                                          \
    void *table##_hscrollbar(const table *self) {                              \
        LOCK(auto ret = ((table##_Derived *)self)->hscrollbar());              \
        return ret;                                                            \
    }                                                                          \
    int table##_find_cell(                                                     \
        const table *self,                                                     \
        int ctx,                                                               \
        int r,                                                                 \
        int c,                                                                 \
        int *x,                                                                \
        int *y,                                                                \
        int *w,                                                                \
        int *h                                                                 \
    ) {                                                                        \
        LOCK(                                                                  \
            auto ret =                                                         \
                ((table##_Derived *)self)->find_cell(ctx, r, c, x, y, w, h)    \
        );                                                                     \
        return ret;                                                            \
    }                                                                          \
    int table##_cursor2rowcol(const table *self, int *r, int *c, int *flag) {  \
        LOCK(                                                                  \
            auto ret = ((table##_Derived *)self)->cursor2rowcol(r, c, flag)    \
        );                                                                     \
        return (int)ret;                                                       \
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
    LOCK(auto ret = self->select_row(row, flag));
    return ret;
}

void Fl_Table_Row_select_all_rows(Fl_Table_Row *self, int flag) {
    LOCK(self->select_all_rows(flag));
}
