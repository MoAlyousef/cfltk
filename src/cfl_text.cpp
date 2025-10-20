#include <cfltk2/cfl_text.h>
#include <cfltk2/cfl_lock.h>
#include <cfltk2/cfl_widget.hpp>

#include <FL/Fl.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Widget.H>

struct Fl_Text_Display_Accessor : public Fl_Text_Display {
    using Fl_Text_Display::absolute_top_line_number;
    using Fl_Text_Display::maintain_absolute_top_line_number;
    using Fl_Text_Display::maintaining_absolute_top_line_number;
    using Fl_Text_Display::reset_absolute_top_line_number;
    using Fl_Text_Display::xy_to_position;
    using Fl_Text_Display::xy_to_rowcol;
};

#define DISPLAY_DEFINE(widget)                                                 \
    int widget##_text_font(const widget *self) {                               \
        LOCK(auto ret = self->textfont());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_text_font(widget *self, int s) {                         \
        LOCK(self->textfont(s));                                               \
    }                                                                          \
    int widget##_text_size(const widget *self) {                               \
        LOCK(auto ret = self->textsize());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_text_size(widget *self, int s) {                         \
        LOCK(self->textsize(s));                                               \
    }                                                                          \
    unsigned int widget##_text_color(const widget *self) {                     \
        LOCK(auto ret = self->textcolor());                                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_text_color(widget *self, unsigned int n) {               \
        LOCK(self->textcolor(n));                                              \
    }                                                                          \
    void widget##_scroll(widget *self, int topLineNum, int horizOffset) {      \
        LOCK(self->scroll(topLineNum, horizOffset));                           \
    }                                                                          \
    void widget##_insert(widget *self, const char *text) {                     \
        LOCK(((Fl_Text_Display *)self)->insert(text));                         \
    }                                                                          \
    void widget##_set_insert_position(widget *self, int newPos) {              \
        LOCK(self->insert_position(newPos));                                   \
    }                                                                          \
    int widget##_insert_position(const widget *self) {                         \
        LOCK(auto ret = self->insert_position());                              \
        return ret;                                                            \
    }                                                                          \
    int widget##_position_to_xy(const widget *self, int pos, int *x, int *y) { \
        LOCK(auto ret = self->position_to_xy(pos, x, y));                      \
        return ret;                                                            \
    }                                                                          \
    int widget##_count_lines(                                                  \
        const widget *self, int start, int end, int start_pos_is_line_start    \
    ) {                                                                        \
        LOCK(                                                                  \
            auto ret = self->count_lines(start, end, start_pos_is_line_start)  \
        );                                                                     \
        return ret;                                                            \
    }                                                                          \
    int widget##_move_right(widget *self) {                                    \
        LOCK(auto ret = self->move_right());                                   \
        return ret;                                                            \
    }                                                                          \
    int widget##_move_left(widget *self) {                                     \
        LOCK(auto ret = self->move_left());                                    \
        return ret;                                                            \
    }                                                                          \
    int widget##_move_up(widget *self) {                                       \
        LOCK(auto ret = self->move_up());                                      \
        return ret;                                                            \
    }                                                                          \
    int widget##_move_down(widget *self) {                                     \
        LOCK(auto ret = self->move_down());                                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_show_cursor(widget *self, int boolean) {                     \
        LOCK(if (boolean) self->show_cursor(); else self->hide_cursor());      \
    }                                                                          \
    void widget##_set_highlight_data(                                          \
        widget *self,                                                          \
        void *sbuff,                                                           \
        unsigned int *color,                                                   \
        int *font,                                                             \
        int *fontsz,                                                           \
        unsigned *attr,                                                        \
        unsigned int *bgcolor,                                                 \
        int sz                                                                 \
    ) {                                                                        \
        Fl_Text_Display::Style_Table_Entry *stable =                           \
            new Fl_Text_Display::Style_Table_Entry[sz];                        \
        if (!stable)                                                           \
            return;                                                            \
        for (int i = 0; i < sz; ++i) {                                         \
            stable[i] = {color[i], font[i], fontsz[i], attr[i], bgcolor[i]};   \
        }                                                                      \
        LOCK(self->highlight_data(                                             \
            (Fl_Text_Buffer *)sbuff, stable, sz, 'A', 0, 0                     \
        ));                                                                    \
    }                                                                          \
    void widget##_set_cursor_style(widget *self, int style) {                  \
        LOCK(self->cursor_style(style));                                       \
    }                                                                          \
    void widget##_set_cursor_color(widget *self, unsigned int color) {         \
        LOCK(self->cursor_color(color));                                       \
    }                                                                          \
    void widget##_set_scrollbar_size(widget *self, int newSize) {              \
        LOCK(self->scrollbar_size(newSize));                                   \
    }                                                                          \
    void widget##_set_scrollbar_align(widget *self, int align) {               \
        LOCK(self->scrollbar_align(align));                                    \
    }                                                                          \
    int widget##_cursor_style(widget *self) {                                  \
        LOCK(auto ret = self->cursor_style());                                 \
        return ret;                                                            \
    }                                                                          \
    unsigned int widget##_cursor_color(widget *self) {                         \
        LOCK(auto ret = self->cursor_color());                                 \
        return ret;                                                            \
    }                                                                          \
    int widget##_scrollbar_size(widget *self) {                                \
        LOCK(auto ret = self->scrollbar_size());                               \
        return ret;                                                            \
    }                                                                          \
    int widget##_scrollbar_align(widget *self) {                               \
        LOCK(auto ret = self->scrollbar_align());                              \
        return ret;                                                            \
    }                                                                          \
    int widget##_line_start(const widget *self, int pos) {                     \
        LOCK(auto ret = self->line_start(pos));                                \
        return ret;                                                            \
    }                                                                          \
    int widget##_line_end(                                                     \
        const widget *self, int startPos, int startPosIsLineStart              \
    ) {                                                                        \
        LOCK(auto ret = self->line_end(startPos, startPosIsLineStart));        \
        return ret;                                                            \
    }                                                                          \
    int widget##_skip_lines(                                                   \
        widget *self, int startPos, int nLines, int startPosIsLineStart        \
    ) {                                                                        \
        LOCK(                                                                  \
            auto ret = self->skip_lines(startPos, nLines, startPosIsLineStart) \
        );                                                                     \
        return ret;                                                            \
    }                                                                          \
    int widget##_rewind_lines(widget *self, int startPos, int nLines) {        \
        LOCK(auto ret = self->rewind_lines(startPos, nLines));                 \
        return ret;                                                            \
    }                                                                          \
    void widget##_next_word(widget *self) {                                    \
        LOCK(self->next_word());                                               \
    }                                                                          \
    void widget##_previous_word(widget *self) {                                \
        LOCK(self->previous_word());                                           \
    }                                                                          \
    int widget##_word_start(const widget *self, int pos) {                     \
        LOCK(auto ret = self->word_start(pos));                                \
        return ret;                                                            \
    }                                                                          \
    int widget##_word_end(const widget *self, int pos) {                       \
        LOCK(auto ret = self->word_end(pos));                                  \
        return ret;                                                            \
    }                                                                          \
    double widget##_x_to_col(const widget *self, double x) {                   \
        LOCK(auto ret = self->x_to_col(x));                                    \
        return ret;                                                            \
    }                                                                          \
    double widget##_col_to_x(const widget *self, double col) {                 \
        LOCK(auto ret = self->col_to_x(col));                                  \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_linenumber_width(widget *self, int width) {              \
        LOCK(self->linenumber_width(width));                                   \
    }                                                                          \
    int widget##_linenumber_width(const widget *self) {                        \
        LOCK(auto ret = self->linenumber_width());                             \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_linenumber_font(widget *self, int val) {                 \
        LOCK(self->linenumber_font(val));                                      \
    }                                                                          \
    int widget##_linenumber_font(const widget *self) {                         \
        LOCK(auto ret = self->linenumber_font());                              \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_linenumber_size(widget *self, int val) {                 \
        LOCK(self->linenumber_size(val));                                      \
    }                                                                          \
    int widget##_linenumber_size(const widget *self) {                         \
        LOCK(auto ret = self->linenumber_size());                              \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_linenumber_fgcolor(widget *self, unsigned int val) {     \
        LOCK(self->linenumber_fgcolor(val));                                   \
    }                                                                          \
    unsigned int widget##_linenumber_fgcolor(const widget *self) {             \
        LOCK(auto ret = self->linenumber_fgcolor());                           \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_linenumber_bgcolor(widget *self, unsigned int val) {     \
        LOCK(self->linenumber_bgcolor(val));                                   \
    }                                                                          \
    unsigned int widget##_linenumber_bgcolor(const widget *self) {             \
        LOCK(auto ret = self->linenumber_bgcolor());                           \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_linenumber_align(widget *self, int val) {                \
        LOCK(self->linenumber_align(val));                                     \
    }                                                                          \
    int widget##_linenumber_align(const widget *self) {                        \
        LOCK(auto ret = self->linenumber_align());                             \
        return ret;                                                            \
    }                                                                          \
    int widget##_in_selection(const widget *self, int x, int y) {              \
        LOCK(auto ret = self->in_selection(x, y));                             \
        return ret;                                                            \
    }                                                                          \
    void widget##_wrap_mode(widget *self, int wrap, int wrap_margin) {         \
        LOCK(self->wrap_mode(wrap, wrap_margin))                               \
    }                                                                          \
    int widget##_wrapped_column(const widget *self, int row, int column) {     \
        LOCK(auto ret = self->wrapped_column(row, column));                    \
        return ret;                                                            \
    }                                                                          \
    int widget##_wrapped_row(const widget *self, int row) {                    \
        LOCK(auto ret = self->wrapped_row(row));                               \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_grammar_underline_color(                                 \
        widget *self, unsigned int color                                       \
    ) {                                                                        \
        LOCK(self->grammar_underline_color((Fl_Color)color));                  \
    }                                                                          \
    unsigned int widget##_grammar_underline_color(const widget *self) {        \
        LOCK(auto ret = self->grammar_underline_color());                      \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_spelling_underline_color(                                \
        widget *self, unsigned int color                                       \
    ) {                                                                        \
        LOCK(self->spelling_underline_color((Fl_Color)color));                 \
    }                                                                          \
    unsigned int widget##_spelling_underline_color(const widget *self) {       \
        LOCK(auto ret = self->spelling_underline_color());                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_secondary_selection_color(                               \
        widget *self, unsigned int color                                       \
    ) {                                                                        \
        LOCK(self->secondary_selection_color((Fl_Color)color));                \
    }                                                                          \
    unsigned int widget##_secondary_selection_color(const widget *self) {      \
        LOCK(auto ret = self->secondary_selection_color());                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_show_insert_position(widget *self) {                         \
        LOCK(self->show_insert_position());                                    \
    }                                                                          \
    void widget##_overstrike(widget *self, const char *text) {                 \
        LOCK(self->overstrike(text));                                          \
    }                                                                          \
    void widget##_redisplay_range(widget *self, int start, int end) {          \
        LOCK(self->redisplay_range(start, end));                               \
    }                                                                          \
    void widget##_set_linenumber_format(widget *self, const char *val) {       \
        LOCK(self->linenumber_format(val));                                    \
    }                                                                          \
    const char *widget##_linenumber_format(const widget *self) {               \
        LOCK(auto ret = self->linenumber_format());                            \
        return ret;                                                            \
    }                                                                          \
    int widget##_position_style(                                               \
        const widget *self, int lineStartPos, int lineLen, int lineIndex       \
    ) {                                                                        \
        LOCK(                                                                  \
            auto ret = self->position_style(lineStartPos, lineLen, lineIndex)  \
        );                                                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_maintain_absolute_top_line_number(widget *self, int state) { \
        LOCK(((Fl_Text_Display_Accessor *)self)                                \
                 ->maintain_absolute_top_line_number(state));                  \
    }                                                                          \
    int widget##_get_absolute_top_line_number(const widget *self) {            \
        LOCK(auto ret = self->get_absolute_top_line_number());                 \
        return ret;                                                            \
    }                                                                          \
    void widget##_absolute_top_line_number(widget *self, int oldFirstChar) {   \
        LOCK(((Fl_Text_Display_Accessor *)self)                                \
                 ->absolute_top_line_number(oldFirstChar));                    \
    }                                                                          \
    int widget##_maintaining_absolute_top_line_number(const widget *self) {    \
        LOCK(                                                                  \
            auto ret = ((Fl_Text_Display_Accessor *)self)                      \
                           ->maintaining_absolute_top_line_number()            \
        );                                                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_reset_absolute_top_line_number(widget *self) {               \
        LOCK(((Fl_Text_Display_Accessor *)self)                                \
                 ->reset_absolute_top_line_number());                          \
    }                                                                          \
    int widget##_scroll_row(const widget *self) {                              \
        LOCK(auto ret = ((Fl_Text_Display_Accessor *)self)->scroll_row());     \
        return ret;                                                            \
    }                                                                          \
    int widget##_scroll_col(const widget *self) {                              \
        LOCK(auto ret = ((Fl_Text_Display_Accessor *)self)->scroll_col());     \
        return ret;                                                            \
    }                                                                          \
    int widget##_xy_to_position(                                               \
        const widget *self, int x, int y, int PosType                          \
    ) {                                                                        \
        LOCK(                                                                  \
            auto ret = ((Fl_Text_Display_Accessor *)self)                      \
                           ->xy_to_position(x, y, PosType)                     \
        );                                                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_xy_to_rowcol(                                                \
        const widget *self, int x, int y, int *row, int *column, int PosType   \
    ) {                                                                        \
        LOCK(((Fl_Text_Display_Accessor *)self)                                \
                 ->xy_to_rowcol(x, y, row, column, PosType));                  \
    }

Fl_Text_Buffer *Fl_Text_Buffer_new(void) {
    LOCK(auto ret = new Fl_Text_Buffer);
    return ret;
}

void Fl_Text_Buffer_delete(Fl_Text_Buffer *self) {
    delete self;
}

const char *Fl_Text_Buffer_text(Fl_Text_Buffer *self) {
    LOCK(auto ret = self->text());
    return ret;
}

void Fl_Text_Buffer_set_text(Fl_Text_Buffer *self, const char *txt) {
    LOCK(self->text(txt));
}

void Fl_Text_Buffer_append(Fl_Text_Buffer *self, const char *txt) {
    LOCK(self->append(txt));
}

void Fl_Text_Buffer_append2(Fl_Text_Buffer *self, const char *txt, int len) {
    LOCK(self->append(txt, len));
}

void Fl_Text_Buffer_remove(Fl_Text_Buffer *self, int start, int end) {
    LOCK(self->remove(start, end));
}

int Fl_Text_Buffer_length(const Fl_Text_Buffer *self) {
    LOCK(auto ret = self->length());
    return ret;
}

char *
Fl_Text_Buffer_text_range(const Fl_Text_Buffer *self, int start, int end) {
    LOCK(auto ret = self->text_range(start, end));
    return ret;
}

void Fl_Text_Buffer_insert(Fl_Text_Buffer *self, int pos, const char *text) {
    LOCK(self->insert(pos, text));
}

void Fl_Text_Buffer_replace(
    Fl_Text_Buffer *self, int start, int end, const char *text
) {
    LOCK(self->replace(start, end, text));
}

void Fl_Text_Buffer_copy(
    Fl_Text_Buffer *self,
    Fl_Text_Buffer *fromBuf,
    int fromStart,
    int fromEnd,
    int toPos
) {
    LOCK(self->copy(fromBuf, fromStart, fromEnd, toPos));
}

int Fl_Text_Buffer_undo(Fl_Text_Buffer *self, int *cp) {
    (void)cp;
    LOCK(auto ret = self->undo(nullptr));
    return ret;
}

void Fl_Text_Buffer_canUndo(Fl_Text_Buffer *self, char flag) {
    LOCK(self->canUndo(flag));
}

int Fl_Text_Buffer_can_undo(const Fl_Text_Buffer *self) {
    LOCK(int ret = self->can_undo());
    return ret;
}

int Fl_Text_Buffer_load_file(Fl_Text_Buffer *self, const char *file) {
    LOCK(auto ret = self->loadfile(file));
    return ret;
}

int Fl_Text_Buffer_save_file(Fl_Text_Buffer *self, const char *file) {
    LOCK(auto ret = self->savefile(file));
    return ret;
}

int Fl_Text_Buffer_tab_distance(const Fl_Text_Buffer *self) {
    LOCK(auto ret = self->tab_distance());
    return ret;
}

void Fl_Text_Buffer_set_tab_distance(Fl_Text_Buffer *self, int tabDist) {
    LOCK(self->tab_distance(tabDist));
}

void Fl_Text_Buffer_select(Fl_Text_Buffer *self, int start, int end) {
    LOCK(self->select(start, end));
}

int Fl_Text_Buffer_selected(const Fl_Text_Buffer *self) {
    LOCK(auto ret = self->selected());
    return ret;
}

void Fl_Text_Buffer_unselect(Fl_Text_Buffer *self) {
    LOCK(self->unselect());
}

int Fl_Text_Buffer_selection_position(
    Fl_Text_Buffer *self, int *start, int *end
) {
    LOCK(auto ret = self->selection_position(start, end));
    return ret;
}

char *Fl_Text_Buffer_selection_text(Fl_Text_Buffer *self) {
    LOCK(auto ret = self->selection_text());
    return ret;
}

void Fl_Text_Buffer_remove_selection(Fl_Text_Buffer *self) {
    LOCK(self->remove_selection());
}

void Fl_Text_Buffer_replace_selection(Fl_Text_Buffer *self, const char *text) {
    LOCK(self->replace_selection(text));
}

void Fl_Text_Buffer_secondary_select(Fl_Text_Buffer *self, int start, int end) {
    LOCK(self->secondary_select(start, end));
}

int Fl_Text_Buffer_secondary_selected(Fl_Text_Buffer *self) {
    LOCK(auto ret = self->secondary_selected());
    return ret;
}

void Fl_Text_Buffer_secondary_unselect(Fl_Text_Buffer *self) {
    LOCK(self->secondary_unselect());
}

int Fl_Text_Buffer_secondary_selection_position(
    Fl_Text_Buffer *self, int *start, int *end
) {
    LOCK(auto ret = self->secondary_selection_position(start, end));
    return ret;
}

char *Fl_Text_Buffer_secondary_selection_text(Fl_Text_Buffer *self) {
    LOCK(auto ret = self->secondary_selection_text());
    return ret;
}

void Fl_Text_Buffer_remove_secondary_selection(Fl_Text_Buffer *self) {
    LOCK(self->remove_secondary_selection());
}

void Fl_Text_Buffer_replace_secondary_selection(
    Fl_Text_Buffer *self, const char *text
) {
    LOCK(self->replace_secondary_selection(text));
}

void Fl_Text_Buffer_highlight(Fl_Text_Buffer *self, int start, int end) {
    LOCK(self->highlight(start, end));
}

int Fl_Text_Buffer_is_highlighted(Fl_Text_Buffer *self) {
    LOCK(auto ret = self->highlight());
    return ret;
}

void Fl_Text_Buffer_unhighlight(Fl_Text_Buffer *self) {
    LOCK(self->unhighlight());
}

int Fl_Text_Buffer_highlight_position(
    Fl_Text_Buffer *self, int *start, int *end
) {
    LOCK(auto ret = self->highlight_position(start, end));
    return ret;
}

char *Fl_Text_Buffer_highlight_text(Fl_Text_Buffer *self) {
    LOCK(auto ret = self->highlight_text());
    return ret;
}

char *Fl_Text_Buffer_line_text(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->line_text(pos));
    return ret;
}

int Fl_Text_Buffer_line_start(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->line_start(pos));
    return ret;
}

int Fl_Text_Buffer_line_end(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->line_end(pos));
    return ret;
}

int Fl_Text_Buffer_word_start(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->word_start(pos));
    return ret;
}

int Fl_Text_Buffer_word_end(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->word_end(pos));
    return ret;
}

int Fl_Text_Buffer_count_lines(
    const Fl_Text_Buffer *self, int startPos, int endPos
) {
    LOCK(auto ret = self->count_lines(startPos, endPos));
    return ret;
}

unsigned int Fl_Text_Buffer_char_at(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->char_at(pos));
    return ret;
}

unsigned char Fl_Text_Buffer_byte_at(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = (unsigned char)self->byte_at(pos));
    return ret;
}

const char *Fl_Text_Buffer_address(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->address(pos));
    return ret;
}

char *Fl_Text_Buffer_address2(Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->address(pos));
    return ret;
}

int Fl_Text_Buffer_utf8_align(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->utf8_align(pos));
    return ret;
}

int Fl_Text_Buffer_is_word_separator(const Fl_Text_Buffer *self, int pos) {
    LOCK(auto ret = self->is_word_separator(pos));
    return ret;
}

void Fl_Text_Buffer_add_modify_callback(
    Fl_Text_Buffer *self, Fl_Text_Modify_Cb bufModifiedCB, void *cbArg
) {
    LOCK(self->add_modify_callback(bufModifiedCB, cbArg));
}

void Fl_Text_Buffer_remove_modify_callback(
    Fl_Text_Buffer *self, Fl_Text_Modify_Cb bufModifiedCB, void *cbArg
) {
    LOCK(self->remove_modify_callback(bufModifiedCB, cbArg));
}

void Fl_Text_Buffer_call_modify_callbacks(Fl_Text_Buffer *self) {
    LOCK(self->call_modify_callbacks());
}

int Fl_Text_Buffer_search_forward(
    const Fl_Text_Buffer *self,
    int start_pos,
    const char *search_string,
    int *found_pos,
    int match_case
) {
    LOCK(
        int ret = self->search_forward(
            start_pos, search_string, found_pos, match_case
        )
    );
    return ret;
}

int Fl_Text_Buffer_search_backward(
    const Fl_Text_Buffer *self,
    int start_pos,
    const char *search_string,
    int *found_pos,
    int match_case
) {
    LOCK(
        int ret = self->search_backward(
            start_pos, search_string, found_pos, match_case
        )
    );
    return ret;
}

int Fl_Text_Buffer_findchar_forward(
    const Fl_Text_Buffer *self,
    int start_pos,
    unsigned int search_char,
    int *found_pos
) {
    LOCK(int ret = self->findchar_forward(start_pos, search_char, found_pos));
    return ret;
}

int Fl_Text_Buffer_findchar_backward(
    const Fl_Text_Buffer *self,
    int start_pos,
    unsigned int search_char,
    int *found_pos
) {
    LOCK(int ret = self->findchar_backward(start_pos, search_char, found_pos));
    return ret;
}

int Fl_Text_Buffer_redo(Fl_Text_Buffer *self, int *cp) {
    LOCK(int ret = self->redo(cp));
    return ret;
}

int Fl_Text_Buffer_can_redo(const Fl_Text_Buffer *self) {
    LOCK(int ret = self->can_redo());
    return ret;
}

int Fl_Text_Buffer_insertfile(
    Fl_Text_Buffer *self, const char *file, int pos, int buflen
) {
    LOCK(int ret = self->insertfile(file, pos, buflen));
    return ret;
}

// P2 additions: pre-delete callbacks
void Fl_Text_Buffer_add_predelete_callback(
    Fl_Text_Buffer *self, Fl_Text_Predelete_Cb bufPredeleteCB, void *cbArg
) {
    LOCK(self->add_predelete_callback(bufPredeleteCB, cbArg));
}

void Fl_Text_Buffer_remove_predelete_callback(
    Fl_Text_Buffer *self, Fl_Text_Predelete_Cb bufPredeleteCB, void *cbArg
) {
    LOCK(self->remove_predelete_callback(bufPredeleteCB, cbArg));
}

void Fl_Text_Buffer_call_predelete_callbacks(Fl_Text_Buffer *self) {
    LOCK(self->call_predelete_callbacks());
}

int Fl_Text_Buffer_appendfile(
    Fl_Text_Buffer *self, const char *file, int buflen
) {
    LOCK(int ret = self->appendfile(file, buflen));
    return ret;
}

int Fl_Text_Buffer_outputfile(
    Fl_Text_Buffer *self, const char *file, int start, int end, int buflen
) {
    LOCK(int ret = self->outputfile(file, start, end, buflen));
    return ret;
}

WIDGET_CLASS(Fl_Text_Display)

WIDGET_DEFINE(Fl_Text_Display)

void Fl_Text_Display_init(Fl_Text_Display *self) {
    LOCK(auto *buff = new Fl_Text_Buffer(); self->buffer(buff));
}

Fl_Text_Buffer *Fl_Text_Display_get_buffer(Fl_Text_Display *self) {
    LOCK(auto ret = self->buffer());
    return ret;
}

void Fl_Text_Display_set_buffer(Fl_Text_Display *self, Fl_Text_Buffer *buf) {
    LOCK(self->buffer(buf));
}

Fl_Text_Buffer *Fl_Text_Display_get_style_buffer(Fl_Text_Display *self) {
    LOCK(auto ret = self->style_buffer());
    return ret;
}

DISPLAY_DEFINE(Fl_Text_Display)

WIDGET_CLASS(Fl_Text_Editor)

WIDGET_DEFINE(Fl_Text_Editor)

void Fl_Text_Editor_init(Fl_Text_Editor *self) {
    LOCK(auto *buff = new Fl_Text_Buffer(); self->buffer(buff));
}

Fl_Text_Buffer *Fl_Text_Editor_get_buffer(Fl_Text_Editor *self) {
    LOCK(auto ret = self->buffer());
    return ret;
}

void Fl_Text_Editor_set_buffer(Fl_Text_Editor *self, Fl_Text_Buffer *buf) {
    LOCK(self->buffer(buf));
}

Fl_Text_Buffer *Fl_Text_Editor_get_style_buffer(Fl_Text_Editor *self) {
    LOCK(auto ret = self->style_buffer());
    return ret;
}

DISPLAY_DEFINE(Fl_Text_Editor)

int Fl_Text_Editor_kf_copy(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_copy(1, e));
    return ret;
}

int Fl_Text_Editor_kf_cut(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_cut(1, e));
    return ret;
}

int Fl_Text_Editor_kf_paste(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_paste(1, e));
    return ret;
}

int Fl_Text_Editor_kf_undo(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_undo(1, e));
    return ret;
}

int Fl_Text_Editor_kf_redo(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_redo(1, e));
    return ret;
}

int Fl_Text_Editor_kf_default(int c, Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_default(c, e));
    return ret;
}

int Fl_Text_Editor_kf_ignore(int c, Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_ignore(c, e));
    return ret;
}

int Fl_Text_Editor_kf_backspace(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_backspace(0, e));
    return ret;
}

int Fl_Text_Editor_kf_enter(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_enter(0, e));
    return ret;
}

int Fl_Text_Editor_kf_move(int c, Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_move(c, e));
    return ret;
}

int Fl_Text_Editor_kf_shift_move(int c, Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_shift_move(c, e));
    return ret;
}

int Fl_Text_Editor_kf_ctrl_move(int c, Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_ctrl_move(c, e));
    return ret;
}

int Fl_Text_Editor_kf_c_s_move(int c, Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_c_s_move(c, e));
    return ret;
}

int Fl_Text_Editor_kf_meta_move(int c, Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_meta_move(c, e));
    return ret;
}

int Fl_Text_Editor_kf_m_s_move(int c, Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_m_s_move(c, e));
    return ret;
}

int Fl_Text_Editor_kf_home(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_home(0, e));
    return ret;
}

int Fl_Text_Editor_kf_end(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_end(0, e));
    return ret;
}

int Fl_Text_Editor_kf_left(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_left(0, e));
    return ret;
}

int Fl_Text_Editor_kf_up(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_up(0, e));
    return ret;
}

int Fl_Text_Editor_kf_right(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_right(0, e));
    return ret;
}

int Fl_Text_Editor_kf_down(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_down(0, e));
    return ret;
}

int Fl_Text_Editor_kf_page_up(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_page_up(0, e));
    return ret;
}

int Fl_Text_Editor_kf_page_down(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_page_down(0, e));
    return ret;
}

int Fl_Text_Editor_kf_insert(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_insert(0, e));
    return ret;
}

int Fl_Text_Editor_kf_delete(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_delete(0, e));
    return ret;
}

int Fl_Text_Editor_kf_select_all(Fl_Text_Editor *e) {
    LOCK(auto ret = Fl_Text_Editor::kf_select_all(0, e));
    return ret;
}

void Fl_Text_Editor_set_insert_mode(Fl_Text_Editor *self, int b) {
    LOCK(self->insert_mode(b));
}

int Fl_Text_Editor_insert_mode(Fl_Text_Editor *self) {
    LOCK(auto ret = self->insert_mode());
    return ret;
}

void Fl_Text_Editor_set_tab_nav(Fl_Text_Editor *self, int val) {
    LOCK(self->tab_nav(val));
}

int Fl_Text_Editor_tab_nav(const Fl_Text_Editor *self) {
    LOCK(auto ret = self->tab_nav());
    return ret;
}

void Fl_Text_Editor_add_key_binding(
    Fl_Text_Editor *self, int key, int state, int (*kf)(int, Fl_Text_Editor *)
) {
    LOCK(self->add_key_binding(key, state, kf));
}

void Fl_Text_Editor_remove_key_binding(
    Fl_Text_Editor *self, int key, int state
) {
    LOCK(self->remove_key_binding(key, state));
}

void Fl_delete_stable(void *stable) {
    delete[] (Fl_Text_Display::Style_Table_Entry *)stable;
}