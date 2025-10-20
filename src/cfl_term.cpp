#include <cfltk2/cfl_lock.h>
#include <cfltk2/cfl_widget.hpp>
#include <cfltk2/cfl_term.h>

#include <FL/fl_draw.H>
#include <FL/Fl_Terminal.H>
#include <stdlib.h>

struct Fl_Terminal_Derived : public Widget_Derived<Fl_Terminal> {
    Fl_Terminal_Derived(const Fl_Terminal_Derived &) = delete;
    Fl_Terminal_Derived(Fl_Terminal_Derived &&) = delete;
    Fl_Terminal_Derived &operator=(const Fl_Terminal_Derived &other) = delete;
    Fl_Terminal_Derived &operator=(Fl_Terminal_Derived &&other)      = delete;

    Fl_Terminal_Derived(int x, int y, int w, int h, const char *title = nullptr)
        : Widget_Derived<Fl_Terminal>(x, y, w, h, title) {
    }

    operator Fl_Terminal *() {
        return (Fl_Terminal *)this;
    }

    struct Utf8Char {
        /// Create a Utf8Char for testing
        static Fl_Terminal::Utf8Char * new_obj(char c) {
            auto x = new Fl_Terminal::Utf8Char;
            auto cs = Fl_Terminal::CharStyle(false);
            x->text_ascii(c, cs);
            return x;
        };
        unsigned attr_bgcolor(Fl_Terminal const *grp) const { return ((Fl_Terminal::Utf8Char *) this)->attr_bg_color(grp); };
        unsigned attr_fgcolor(Fl_Terminal const *grp) const { return ((Fl_Terminal::Utf8Char *) this)->attr_fg_color(grp); };
        unsigned char attrib(void) const {
            return ((Fl_Terminal::Utf8Char *) this)->attrib();
        };
        unsigned bgcolor(void) const {
            return ((Fl_Terminal::Utf8Char *) this)->bgcolor();
        };
        unsigned fgcolor(void) const { return ((Fl_Terminal::Utf8Char *) this)->fgcolor(); };
        int is_char(char c) const { return ((Fl_Terminal::Utf8Char *) this)->is_char(c); };     // boolean
        unsigned char charflags(void) const { return ((Fl_Terminal::Utf8Char *) this)->charflags(); };
        const char* text_utf8(void) const { return ((Fl_Terminal::Utf8Char *) this)->text_utf8(); };
        int length(void) const { return ((Fl_Terminal::Utf8Char *) this)->length(); };
        int max_utf8(void) const { return ((Fl_Terminal::Utf8Char *) this)->max_utf8(); };
        double pwidth(void) const { return ((Fl_Terminal::Utf8Char *) this)->pwidth(); };
        int pwidth_int(void) const { return ((Fl_Terminal::Utf8Char *) this)->pwidth_int(); };
        static const unsigned size = sizeof(Fl_Terminal::Utf8Char);
    };

    // const char *get_selection_text() const {
    //     return this->selection_text();
    // }

    void clear_mouse_selection(void) {
        Fl_Terminal::clear_mouse_selection();
    }

    void set_cursor_col(int val) {
        Fl_Terminal::cursor_col(val);
    }

    void set_cursor_row(int val) {
        Fl_Terminal::cursor_row(val);
    }

    void cursor_up(int count, bool do_scroll) {
        Fl_Terminal::cursor_up(count, do_scroll);
    }

    void cursor_down(int count, bool do_scroll) {
        Fl_Terminal::cursor_down(count, do_scroll);
    }

    void cursor_left(int count) {
        Fl_Terminal::cursor_left(count);
    }

    void cursor_right(int count, bool do_scroll) {
        Fl_Terminal::cursor_right(count, do_scroll);
    }

    void scroll(int count) {
        Fl_Terminal::scroll(count);
    }

    void clear_eod(void) {
        Fl_Terminal::clear_eod();
    }

    void clear_eol(void) {
        Fl_Terminal::clear_eol();
    }

    void clear_line(void) {
        Fl_Terminal::clear_line();
    }

    void clear_line(int drow) {
        Fl_Terminal::clear_line(drow);
    }

    void clear_sod(void) {
        Fl_Terminal::clear_sod();
    }

    void clear_sol(void) {
        Fl_Terminal::clear_sol();
    }

    void insert_char(char c, int rep) {
        Fl_Terminal::insert_char(c, rep);
    }

    void insert_char_eol(char c, int drow, int dcol, int rep) {
        Fl_Terminal::insert_char_eol(c, drow, dcol, rep);
    }

    void insert_rows(int count) {
        Fl_Terminal::insert_rows(count);
    }

    void delete_cur_chars(int count) {
        Fl_Terminal::delete_chars(count);
    }

    void delete_chars(int drow, int dcol, int count) {
        Fl_Terminal::delete_chars(drow, dcol, count);
    }

    void delete_rows(int count) {
        Fl_Terminal::delete_rows(count);
    }


    // returns bool false for no selection
    int get_selection(int &srow, int &scol, int &erow, int &ecol) {
        return Fl_Terminal::get_selection(srow, scol, erow, ecol);
    }

    int w_to_col(int W) const {
        return Fl_Terminal::w_to_col(W);
    }
    int h_to_row(int H) const {
        return Fl_Terminal::h_to_row(H);
    };

    int disp_erow(void) const {
        return Fl_Terminal::disp_erow();
    }
    int disp_srow(void) const {
        return Fl_Terminal::disp_srow();
    }
    int hist_erow(void) const {
        return Fl_Terminal::hist_erow();
    }
    int hist_srow(void) const {
        return Fl_Terminal::hist_srow();
    }
    int hist_use(void) const {
        return Fl_Terminal::hist_use();
    }
    int hist_use_srow(void) const {
        return Fl_Terminal::hist_use_srow();
    }
    int is_inside_selection(int row, int col) const {
        return Fl_Terminal::is_inside_selection(row, col);
    }
    int is_selection(void) const {
        return Fl_Terminal::is_selection();
    }
    int offset(void) const {
        return Fl_Terminal::offset();
    }
    int ring_erow(void) const {
        return Fl_Terminal::ring_erow();
    }
    int ring_srow(void) const {
        return Fl_Terminal::ring_srow();
    }
    int ring_rows(void) const {
        return Fl_Terminal::ring_rows();
    }
    const Fl_Terminal::Utf8Char *u8c_cursor()  {
        return Fl_Terminal::u8c_cursor();
    }

    const Fl_Terminal::Utf8Char *u8c_disp_row(int drow) const {
        return Fl_Terminal::u8c_disp_row(drow);
    }
    const Fl_Terminal::Utf8Char *u8c_hist_row(int hrow) const {
        return Fl_Terminal::u8c_hist_row(hrow);
    }
    const Fl_Terminal::Utf8Char *u8c_hist_use_row(int hurow) const {
        return Fl_Terminal::u8c_hist_use_row(hurow);
    }
    const Fl_Terminal::Utf8Char *u8c_ring_row(int grow) const {
        return Fl_Terminal::u8c_ring_row(grow);
    }
};

WIDGET_DEFINE(Fl_Terminal)

void Fl_Terminal_set_ansi(Fl_Terminal *self, int boolean) {
    LOCK(self->ansi(boolean));
}

int Fl_Terminal_ansi(Fl_Terminal const *self) {
    LOCK(auto ret = self->ansi());
    return ret;
}

void Fl_Terminal_append(Fl_Terminal *self, const char *txt) {
    LOCK(self->append(txt));
}

void Fl_Terminal_append_u8(Fl_Terminal *self, const char *txt, int len) {
    LOCK(self->append(txt, len));
}

void Fl_Terminal_append_ascii(Fl_Terminal *self, const char *txt) {
    LOCK(self->append_ascii(txt));
}

void Fl_Terminal_append_utf8(Fl_Terminal *self, const char *txt) {
    LOCK(self->append_utf8(txt));
}

void Fl_Terminal_append_utf8_u8(Fl_Terminal *self, const char *txt, int len) {
    LOCK(self->append_utf8(txt, len));
}

void Fl_Terminal_clear_history(Fl_Terminal *self) {
    LOCK(self->clear_history());
}

// Fl_Terminal_clear() is defined in macros

void Fl_Terminal_clear_to_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->clear((Fl_Color)set));
}

void Fl_Terminal_clear_screen(Fl_Terminal *self, int boolean) {
    LOCK(self->clear_screen(boolean));
}

void Fl_Terminal_clear_screen_home(Fl_Terminal *self, int boolean) {
    LOCK(self->clear_screen_home(boolean));
}

int Fl_Terminal_cursor_col(Fl_Terminal const *self) {
    LOCK(auto ret = self->cursor_col());
    return ret;
}

void Fl_Terminal_cursor_home(Fl_Terminal *self) {
    LOCK(self->cursor_home());
}

int Fl_Terminal_cursor_row(Fl_Terminal const *self) {
    LOCK(auto ret = self->cursor_row());
    return ret;
}

unsigned Fl_Terminal_cursor_bg_color(Fl_Terminal const *self) {
    LOCK(auto ret = self->cursorbgcolor());
    return ret;
}

void Fl_Terminal_set_cursor_bg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->cursorbgcolor((Fl_Color)set));
}

unsigned Fl_Terminal_cursor_fg_color(Fl_Terminal const *self) {
    LOCK(auto ret = self->cursorfgcolor());
    return ret;
}

void Fl_Terminal_set_cursor_fg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->cursorfgcolor((Fl_Color)set));
}

int Fl_Terminal_display_columns(Fl_Terminal const *self) {
    LOCK(auto ret = self->display_columns());
    return ret;
}

void Fl_Terminal_set_display_columns(Fl_Terminal *self, int set) {
    LOCK(self->display_columns(set));
}

int Fl_Terminal_display_rows(Fl_Terminal const *self) {
    LOCK(auto ret = self->display_rows());
    return ret;
}

int Fl_Terminal_history_rows(Fl_Terminal const *self) {
    LOCK(auto ret = self->history_rows());
    return ret;
}

void Fl_Terminal_set_history_rows(Fl_Terminal *self, int set) {
    LOCK(self->history_rows(set));
}

int Fl_Terminal_history_use(Fl_Terminal const *self) {
    LOCK(auto ret = self->history_use());
    return ret;
}

int Fl_Terminal_margin_bottom(Fl_Terminal const *self) {
    LOCK(auto ret = self->margin_bottom());
    return ret;
}

void Fl_Terminal_set_margin_bottom(Fl_Terminal *self, int set) {
    LOCK(self->margin_bottom(set));
}

int Fl_Terminal_margin_left(Fl_Terminal const *self) {
    LOCK(auto ret = self->margin_left());
    return ret;
}

void Fl_Terminal_set_margin_left(Fl_Terminal *self, int set) {
    LOCK(self->margin_left(set));
}

int Fl_Terminal_margin_right(Fl_Terminal const *self) {
    LOCK(auto ret = self->margin_right());
    return ret;
}

void Fl_Terminal_set_margin_right(Fl_Terminal *self, int set) {
    LOCK(self->margin_right(set));
}

int Fl_Terminal_margin_top(Fl_Terminal const *self) {
    LOCK(auto ret = self->margin_top());
    return ret;
}

void Fl_Terminal_set_margin_top(Fl_Terminal *self, int set) {
    LOCK(self->margin_top(set));
}

unsigned Fl_Terminal_output_translate(Fl_Terminal const *self
) { // Returns OutFlags
    LOCK(auto ret = self->output_translate());
    return ret;
}

void Fl_Terminal_set_output_translate(Fl_Terminal *self, unsigned set) {
    LOCK(self->output_translate((Fl_Terminal::OutFlags) set));
}

void Fl_Terminal_print_char(Fl_Terminal *self, char c) {
    LOCK(self->print_char(c));
}

void Fl_Terminal_print_char_utf8(Fl_Terminal *self, const char *txt, int len) {
    LOCK(self->print_char(txt, len));
}

void Fl_Terminal_plot_char(Fl_Terminal *self, char c, int row, int col) {
    LOCK(self->plot_char(c, row, col));
}

void Fl_Terminal_plot_char_utf8(
    Fl_Terminal *self, const char *txt, int len, int drow, int dcol
) {
    LOCK(self->plot_char(txt, len, drow, dcol));
}

float Fl_Terminal_redraw_rate(Fl_Terminal const *self) {
    LOCK(auto ret = self->redraw_rate());
    return ret;
}

void Fl_Terminal_set_redraw_rate(Fl_Terminal *self, float set) {
    LOCK(self->redraw_rate(set));
}

int Fl_Terminal_redraw_style(Fl_Terminal const *self
) { // Actually returns enum RedrawStyle
    LOCK(auto ret = self->redraw_style());
    return ret;
}

void Fl_Terminal_set_redraw_style(Fl_Terminal *self, int set) {
    LOCK(self->redraw_style((Fl_Terminal::RedrawStyle)set));
}

void Fl_Terminal_reset_terminal(Fl_Terminal *self) {
    LOCK(self->reset_terminal());
}

int Fl_Terminal_scrollbar_actual_size(Fl_Terminal const *self) {
    LOCK(auto ret = self->scrollbar_actual_size());
    return ret;
}

int Fl_Terminal_scrollbar_size(Fl_Terminal const *self) {
    LOCK(auto ret = self->scrollbar_size());
    return ret;
}

void Fl_Terminal_set_scrollbar_size(Fl_Terminal *self, int set) {
    LOCK(self->scrollbar_size(set));
}

int Fl_Terminal_hscrollbar_style(Fl_Terminal const *self) {  // Actually returns enum ScrollbarStyle
    LOCK(auto ret = self->hscrollbar_style());
    return ret;
}

void Fl_Terminal_set_hscrollbar_style(Fl_Terminal *self, int set) {
    LOCK(self->hscrollbar_style((Fl_Terminal::ScrollbarStyle) set));
}

unsigned Fl_Terminal_selection_bg_color(Fl_Terminal const *self
) { // Actually returns Fl_Color
    LOCK(auto ret = self->selectionbgcolor());
    return ret;
}

void Fl_Terminal_set_selection_bg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->selectionbgcolor(set));
}

unsigned Fl_Terminal_selection_fg_color(Fl_Terminal const *self
) { // Actually returns Fl_Color
    LOCK(auto ret = self->selectionfgcolor());
    return ret;
}

void Fl_Terminal_set_selection_fg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->selectionfgcolor(set));
}

int Fl_Terminal_show_unknown(Fl_Terminal const *self) {
    LOCK(auto ret = self->show_unknown());
    return ret;
}

void Fl_Terminal_set_show_unknown(Fl_Terminal *self, int boolean) {
    LOCK(self->show_unknown(boolean));
}

unsigned char Fl_Terminal_text_attrib(Fl_Terminal const *self) {
    LOCK(auto ret = self->textattrib());
    return ret;
}

void Fl_Terminal_set_text_attrib(Fl_Terminal *self, unsigned char set) {
    LOCK(self->textattrib(set));
}

unsigned Fl_Terminal_text_bg_color(Fl_Terminal const *self
) { // Actually returns Fl_Color
    LOCK(auto ret = self->textbgcolor());
    return ret;
}

void Fl_Terminal_set_text_bg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->textbgcolor(set));
}

unsigned Fl_Terminal_text_bg_color_default(Fl_Terminal const *self
) { // Actually returns Fl_Color
    LOCK(auto ret = self->textbgcolor_default());
    return ret;
}

void Fl_Terminal_set_text_bg_color_default(Fl_Terminal *self, unsigned set) {
    LOCK(self->textbgcolor_default(set));
}

void Fl_Terminal_set_text_bg_color_xterm(Fl_Terminal *self, unsigned char set) {
    LOCK(self->textbgcolor_xterm(set));
}

void Fl_Terminal_set_text_color(
    Fl_Terminal *self,
    unsigned set
) { // Actually Fl_Color
    LOCK(self->textcolor(set));
}

unsigned Fl_Terminal_text_fg_color(Fl_Terminal const *self
) { // Actually returns Fl_Color
    LOCK(auto ret = self->textfgcolor());
    return ret;
}

void Fl_Terminal_set_text_fg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->textfgcolor(set));
}

unsigned Fl_Terminal_text_fg_color_default(Fl_Terminal const *self
) { // Actually returns Fl_Color
    LOCK(auto ret = self->textfgcolor_default());
    return ret;
}

void Fl_Terminal_set_text_fg_color_default(Fl_Terminal *self, unsigned set) {
    LOCK(self->textfgcolor_default(set));
}

void Fl_Terminal_set_text_fg_color_xterm(Fl_Terminal *self, unsigned char set) {
    LOCK(self->textfgcolor_xterm(set));
}

int Fl_Terminal_text_font(Fl_Terminal const *self) { // Actually Fl_Font
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Terminal_set_text_font(Fl_Terminal *self, int set) {
    LOCK(self->textfont(set));
}

int Fl_Terminal_text_size(Fl_Terminal const *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

void Fl_Terminal_set_text_size(Fl_Terminal *self, int set) {
    LOCK(self->textsize(set));
}

/// printf is not used by Rust but might be useful for C programs using this
/// interface.
/// String is limited to no longer than 1024 characters including NULL terminator.
void Fl_Terminal_printf(Fl_Terminal *self, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    LOCK(self->vprintf(fmt, ap));
    va_end(ap);
}

/**
  Return a string copy of all lines in the terminal (including history).
  The returned string is allocated with strdup(3), which the caller must free.

  If \p 'lines_below_cursor' is false (default), lines below the cursor on down
  to the bottom of the display are ignored, and not included in the returned string.

  If \p 'lines_below_cursor' is true, then all lines in the display are returned
  including any below the cursor, even if all are blank.
*/
const char* Fl_Terminal_text(Fl_Terminal const *self, int lines_below_cursor) {       // Argument is bool
    LOCK(auto ret = self->text(lines_below_cursor));
    return ret;
}

const char *Fl_Terminal_selection_text(const Fl_Terminal *self) {
    LOCK(auto ret = self->selection_text());
    return ret;
}

int Fl_Terminal_selection_text_len(const Fl_Terminal *self) {
    LOCK(auto ret = self->selection_text_len());
    return ret;
}



/////////////////////////////////////////////////////////////////////////////////////////
// Access to terminal widget's vertical and horizontal scrollbar
Fl_Terminal_Scrollbar * Fl_Terminal_scrollbar(Fl_Terminal *self) {
    return self->scrollbar;
}

Fl_Terminal_Scrollbar * Fl_Terminal_hscrollbar(Fl_Terminal *self) {
    return self->hscrollbar;
}


/////////////////////////////////////////////////////////////////////////////////////////
// Protected Fl_Terminal methods:

/// Clear any current mouse selection.
void Fl_Terminal_clear_mouse_selection(Fl_Terminal *self) {
    LOCK(((Fl_Terminal_Derived *) self)->clear_mouse_selection());
}

/// Set the cursor's current column position on the screen.
void Fl_Terminal_set_cursor_col(Fl_Terminal *self, int val) {
    // (Note: the cursor_col() getter is public, not protected)
    LOCK(((Fl_Terminal_Derived *) self)->set_cursor_col(val));
}

/// Set the cursor's current row position on the screen.
void Fl_Terminal_set_cursor_row(Fl_Terminal *self, int val) {
    // (Note: the cursor_row() getter is public, not protected)
    LOCK(((Fl_Terminal_Derived *) self)->set_cursor_row(val));
}

void Fl_Terminal_cursor_up(Fl_Terminal *self, int count, int do_scroll) {
    LOCK(((Fl_Terminal_Derived *) self)->cursor_up(count, (bool) do_scroll));
}

void Fl_Terminal_cursor_down(Fl_Terminal *self, int count, int do_scroll) {
    LOCK(((Fl_Terminal_Derived *) self)->cursor_down(count, (bool) do_scroll));
}

void Fl_Terminal_cursor_left(Fl_Terminal *self, int count) {
    LOCK(((Fl_Terminal_Derived *) self)->cursor_left(count));
}

void Fl_Terminal_cursor_right(Fl_Terminal *self, int count, int do_scroll) {
    LOCK(((Fl_Terminal_Derived *) self)->cursor_right(count, (bool) do_scroll));
}

void Fl_Terminal_scroll(Fl_Terminal *self, int count) {
    LOCK(((Fl_Terminal_Derived *) self)->scroll(count));
}

void Fl_Terminal_clear_eod(Fl_Terminal *self) {
    LOCK(((Fl_Terminal_Derived *) self)->clear_eod());
}

void Fl_Terminal_clear_eol(Fl_Terminal *self) {
    LOCK(((Fl_Terminal_Derived *) self)->clear_eol());
}

void Fl_Terminal_clear_cur_line(Fl_Terminal *self) {
    LOCK(((Fl_Terminal_Derived *) self)->clear_line());
}

void Fl_Terminal_clear_line(Fl_Terminal *self, int drow) {
    LOCK(((Fl_Terminal_Derived *) self)->clear_line(drow));
}

void Fl_Terminal_clear_sod(Fl_Terminal *self) {
    LOCK(((Fl_Terminal_Derived *) self)->clear_sod());
}

void Fl_Terminal_clear_sol(Fl_Terminal *self) {
    LOCK(((Fl_Terminal_Derived *) self)->clear_sol());
}

void Fl_Terminal_insert_char(Fl_Terminal *self, char c, int rep) {
    LOCK(((Fl_Terminal_Derived *) self)->insert_char(c, rep));
}

void Fl_Terminal_insert_char_eol(Fl_Terminal *self, char c, int drow, int dcol, int rep) {
    LOCK(((Fl_Terminal_Derived *) self)->insert_char_eol(c, drow, dcol, rep));
}

void Fl_Terminal_insert_rows(Fl_Terminal *self, int count) {
    LOCK(((Fl_Terminal_Derived *) self)->insert_rows(count));
}

void Fl_Terminal_delete_cur_chars(Fl_Terminal *self, int rep) {
    LOCK(((Fl_Terminal_Derived *) self)->delete_cur_chars(rep));
}

void Fl_Terminal_delete_chars(Fl_Terminal *self, int drow, int dcol, int rep) {
    LOCK(((Fl_Terminal_Derived *) self)->delete_chars(drow, dcol, rep));
}

void Fl_Terminal_delete_rows(Fl_Terminal *self, int count) {
    LOCK(((Fl_Terminal_Derived *) self)->delete_rows(count));
}

int Fl_Terminal_h_to_row(Fl_Terminal const *self, int H) {
    LOCK(auto ret = ((Fl_Terminal_Derived *)self)->h_to_row(H));
    return ret;
}

int Fl_Terminal_w_to_col(Fl_Terminal const *self, int W) {
    LOCK(auto ret = ((Fl_Terminal_Derived *)self)->w_to_col(W));
    return ret;
}

/// Places four integers (srow, scol, erow, ecol) into the provided buffer, which should be a uint32_t[4] array
/// bool return falue is FALSE if no selection exists
int Fl_Terminal_get_selection(Fl_Terminal const *self, int *results) {
    LOCK(auto ret = ((Fl_Terminal_Derived *)self)->get_selection(results[0], results[1], results[2], results[3]));
    return ret;
}


/////////////////////////////////////////////////////////////////////////////////////////
// Utf8Char class methods.
// So far, only "getters" are implemented. No "setters", so no way
// to modify a Utf8 object.


/// Get the bg color of char `u8c` possibly influenced by BOLD or DIM.
///    If a `grp` widget is specified (i.e. not `NULL`), don't let the color be
///    influenced by the attribute bits *if* it matches the `grp` widget's own color().
unsigned Fl_Terminal_Utf8Char_attr_bgcolor(Fl_Terminal_Utf8Char const *self, Fl_Terminal const *grp) { // Actually returns Fl_Color
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->attr_bgcolor(grp));
    return ret;
}

/// Get the fg color of char `u8c` possibly influenced by BOLD or DIM.
///    If a `grp` widget is specified (i.e. not `NULL`), don't let the color be
///    influenced by the attribute bits *if* it matches the `grp` widget's own color().
unsigned Fl_Terminal_Utf8Char_attr_fgcolor(Fl_Terminal_Utf8Char const *self, Fl_Terminal const *grp) { // Actually returns Fl_Color
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->attr_fgcolor(grp));
    return ret;
}

/// Get attributes (NORMAL, BOLD, etc.) for this character. Return values are defined in Fl_Terminal::Attrib
unsigned char Fl_Terminal_Utf8Char_attrib(Fl_Terminal_Utf8Char const *self) {
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->attrib());
    return ret;
}

/// Get background color of this character
unsigned Fl_Terminal_Utf8Char_bgcolor(Fl_Terminal_Utf8Char const *self
) { // Actually returns Fl_Color
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->bgcolor());
    return ret;
}

/// Get foreground color of this character
unsigned Fl_Terminal_Utf8Char_fgcolor(Fl_Terminal_Utf8Char const *self
) { // Actually returns Fl_Color
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->fgcolor());
    return ret;
}

int Fl_Terminal_Utf8Char_is_char(Fl_Terminal_Utf8Char const *self, char c) {
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->is_char(c));
    return ret;
}

/// Get maximum length of bytes in text_utf8 -- const 4 per RFC 3629
int Fl_Terminal_Utf8Char_max_utf8(Fl_Terminal_Utf8Char const *self) {
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->max_utf8());
    return ret;
}

double Fl_Terminal_Utf8Char_pwidth(Fl_Terminal_Utf8Char const *self) {
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->pwidth());
    return ret;
}

int Fl_Terminal_Utf8Char_pwidth_int(Fl_Terminal_Utf8Char const *self) {
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->pwidth_int());
    return ret;
}

const unsigned char *
Fl_Terminal_Utf8Char_text_utf8(Fl_Terminal_Utf8Char const *self) {
    auto self1 = (Fl_Terminal_Derived::Utf8Char *)self;
    LOCK(auto ret = (const unsigned char *)self1->text_utf8());
    return ret;
}

/// Get length of bytes in text_utf8: 1 for ASCII, >1 for UTF-8
int Fl_Terminal_Utf8Char_length(Fl_Terminal_Utf8Char const *self) {
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->length());
    return ret;
}

/// Get xterm CharFlags bits
unsigned char Fl_Terminal_Utf8Char_charflags(Fl_Terminal_Utf8Char const *self) {
    auto self1 = (Fl_Terminal_Derived::Utf8Char *) self;
    LOCK(auto ret = self1->charflags());
    return ret;
}

/// Construct a UTF8Char (useful for testing)
Fl_Terminal_Utf8Char * Fl_Terminal_Utf8Char_new_obj(unsigned char c) {
    LOCK(auto ret = Fl_Terminal_Derived::Utf8Char::new_obj(c));
    return ret;
}


// const char *Fl_Terminal_selection_text(const Fl_Terminal *self) {
//     LOCK(auto ret = ((Fl_Terminal_Derived *)self)->get_selection_text());
//     return ret;
// }


/////////////////////////////////////////////////////////////////////////////////////////
// The following are protected functions used to access ring buffer text:

/// Return text selection (for copy()/paste() operations)

///  Return the ending row# in the display area.
int Fl_Terminal_disp_erow(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->disp_erow());
    return ret;
}

/// Return the starting row# in the display area.
int Fl_Terminal_disp_srow(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->disp_srow());
    return ret;
}

/// Return the ending row# of the scrollback history.
int Fl_Terminal_hist_erow(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->hist_erow());
    return ret;
}

/// Return the starting row# of the scrollback history.
int Fl_Terminal_hist_srow(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->hist_srow());
    return ret;
}

/// Return number of rows in use by the scrollback history.
int Fl_Terminal_hist_use(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->hist_use());
    return ret;
}

/// Return the starting row of the "in use" scrollback history.
int Fl_Terminal_hist_use_srow(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->hist_use_srow());
    return ret;
}

/// Is global row/column inside the current mouse selection?
int Fl_Terminal_is_inside_selection(
    Fl_Terminal const *self, int row, int col
) { // Actual return type is bool
    LOCK(
        auto ret = ((Fl_Terminal_Derived *)self)->is_inside_selection(row, col)
    );
    return ret;
}

/// Returns true if there's a mouse selection.
int Fl_Terminal_is_selection(Fl_Terminal const *self
) { // Actual return type is bool
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->is_selection());
    return ret;
}

/// Returns the current offset into the ring buffer.
int Fl_Terminal_offset(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->offset());
    return ret;
}


/// Return the ending row# in the ring buffer (Always ring_rows()-1)
int Fl_Terminal_ring_erow(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->ring_erow());
    return ret;
}

/// Return the starting row# in the ring buffer (Always 0)
int Fl_Terminal_ring_srow(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->ring_srow());
    return ret;
}

/// Return the number of rows in the ring buffer.
int Fl_Terminal_ring_rows(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->ring_rows());
    return ret;
}

/// Return pointer to the first u8c character in row drow of the display.
const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_disp_row(Fl_Terminal const *self, int drow) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->u8c_disp_row(drow));
    return ret;
}

/// Return u8c for beginning of a row inside the scrollback history.
const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_hist_row(Fl_Terminal const *self, int hrow) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->u8c_hist_row(hrow));
    return ret;
}

/// Return u8c for beginning of row hurow inside the 'in use' part of the
/// scrollback history.
const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_hist_use_row(Fl_Terminal const *self, int hurow) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->u8c_hist_use_row(hurow));
    return ret;
}

/// Return the Utf8Char* for character under cursor.
const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_cursor(Fl_Terminal const *self) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->u8c_cursor());
    return ret;
}

/// Return UTF-8 char for row grow in the ring buffer.
const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_ring_row(Fl_Terminal const *self, int grow) {
    LOCK(auto ret = ((Fl_Terminal_Derived *) self)->u8c_ring_row(grow));
    return ret;
}

/////////////////////////////////////////////////////////////////////////////////////////
// BuffRow class methods.
// BuffRow is a Rust class, not corresponding to anything in the C++ code
// It exists to allow clean indexing and iterators at the Rust level

const unsigned Fl_Terminal_Utf8Char_size(void) {
    return Fl_Terminal_Derived::Utf8Char::size;
}

GROUP_DEFINE(Fl_Terminal)

// Free up string that was allocated in C++
void Fl_free_str(const char *str) {
    if (str) free((void *) str);
}
