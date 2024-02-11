#ifndef __CFL_PREFS_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Fl_Preferences Fl_Preferences;

void Fl_Preferences_set_file_access(unsigned int flags);

unsigned int Fl_Preferences_file_access(void);

char Fl_Preferences_remove(void *id_);

Fl_Preferences *
Fl_Preferences_new(int root, const char *vendor, const char *application);

Fl_Preferences *Fl_Preferences_from_path(
    const char *path, const char *vendor, const char *application
);

Fl_Preferences *
Fl_Preferences_from_parent_group(Fl_Preferences *parent, const char *group);

Fl_Preferences *
Fl_Preferences_from_parent_idx(Fl_Preferences *parent, int groupIndex);

Fl_Preferences *Fl_Preferences_copy(const Fl_Preferences *);

void Fl_Preferences_delete(Fl_Preferences *);

Fl_Preferences *Fl_Preferences_from_id(void *id);

int Fl_Preferences_filename(
    Fl_Preferences *prefs, char *buffer, unsigned long buffer_size
);

char Fl_Preferences_get_userdata_path(
    Fl_Preferences *prefs, char *path, int pathlen
);

void *Fl_Preferences_id(Fl_Preferences *prefs);

const char *Fl_Preferences_name(Fl_Preferences *prefs);

const char *Fl_Preferences_path(Fl_Preferences *prefs);

int Fl_Preferences_groups(Fl_Preferences *prefs);

const char *Fl_Preferences_group(Fl_Preferences *prefs, int num_group);

char Fl_Preferences_group_exists(Fl_Preferences *prefs, const char *key);

char Fl_Preferences_delete_group(Fl_Preferences *prefs, const char *group);

char Fl_Preferences_delete_all_groups(Fl_Preferences *prefs);

int Fl_Preferences_entries(Fl_Preferences *prefs);

const char *Fl_Preferences_entry(Fl_Preferences *prefs, int index);

char Fl_Preferences_entry_exists(Fl_Preferences *prefs, const char *key);

char Fl_Preferences_delete_entry(Fl_Preferences *prefs, const char *entry);

char Fl_Preferences_delete_all_entries(Fl_Preferences *prefs);

char Fl_Preferences_clear(Fl_Preferences *prefs);

char Fl_Preferences_seti(Fl_Preferences *prefs, const char *entry, int value);

char Fl_Preferences_setf(Fl_Preferences *prefs, const char *entry, float value);

char Fl_Preferences_setfp(
    Fl_Preferences *prefs, const char *entry, float value, int precision
);

char Fl_Preferences_setd(
    Fl_Preferences *prefs, const char *entry, double value
);

char Fl_Preferences_setdp(
    Fl_Preferences *prefs, const char *entry, double value, int precision
);

char Fl_Preferences_sets(
    Fl_Preferences *prefs, const char *entry, const char *value
);

char Fl_Preferences_setv(
    Fl_Preferences *prefs, const char *entry, const void *value, int size
);

char Fl_Preferences_geti(
    Fl_Preferences *prefs, const char *entry, int *value, int defaultValue
);

char Fl_Preferences_getf(
    Fl_Preferences *prefs, const char *entry, float *value, float defaultValue
);

char Fl_Preferences_getd(
    Fl_Preferences *prefs, const char *entry, double *value, double defaultValue
);

char Fl_Preferences_gets(
    Fl_Preferences *prefs,
    const char *entry,
    char *value,
    const char *defaultValue,
    int maxSize
);

char Fl_Preferences_getv(
    Fl_Preferences *prefs,
    const char *entry,
    void *value,
    const void *defaultValue,
    int defaultSize,
    int maxSize
);

char Fl_Preferences_getv2(
    Fl_Preferences *prefs,
    const char *entry,
    void *value,
    const void *defaultValue,
    int defaultSize,
    int *size
);

int Fl_Preferences_size(Fl_Preferences *prefs, const char *entry);

#ifdef __cplusplus
}
#endif
#endif