#include "cfl_prefs.h"

#include <FL/Fl_Preferences.H>

void Fl_Preferences_set_file_access(unsigned int flags) {
    Fl_Preferences::file_access(flags);
}

unsigned int Fl_Preferences_file_access(void) {
    return Fl_Preferences::file_access();
}

char Fl_Preferences_remove(void *id_) {
    return Fl_Preferences::remove(id_);
}

Fl_Preferences *
Fl_Preferences_new(int root, const char *vendor, const char *application) {
    return new Fl_Preferences((Fl_Preferences::Root)root, vendor, application);
}

Fl_Preferences *Fl_Preferences_from_path(
    const char *path, const char *vendor, const char *application
) {
    return new Fl_Preferences(path, vendor, application);
}

Fl_Preferences *
Fl_Preferences_from_parent_group(Fl_Preferences *parent, const char *group) {
    return new Fl_Preferences(parent, group);
}

Fl_Preferences *
Fl_Preferences_from_parent_idx(Fl_Preferences *parent, int groupIndex) {
    return new Fl_Preferences(parent, groupIndex);
}

Fl_Preferences *Fl_Preferences_copy(const Fl_Preferences *other) {
    return new Fl_Preferences(*other);
}

void Fl_Preferences_delete(Fl_Preferences *self_) {
    delete self_;
}

Fl_Preferences *Fl_Preferences_from_id(void *id) {
    return new Fl_Preferences(id);
}

int Fl_Preferences_filename(
    Fl_Preferences *prefs, char *buffer, unsigned long buffer_size
) {
    return prefs->filename(buffer, buffer_size);
}

char Fl_Preferences_get_userdata_path(
    Fl_Preferences *prefs, char *path, int pathlen
) {
    return prefs->get_userdata_path(path, pathlen);
}

void *Fl_Preferences_id(Fl_Preferences *prefs) {
    return prefs->id();
}

const char *Fl_Preferences_name(Fl_Preferences *prefs) {
    return prefs->name();
}

const char *Fl_Preferences_path(Fl_Preferences *prefs) {
    return prefs->path();
}

int Fl_Preferences_groups(Fl_Preferences *prefs) {
    return prefs->groups();
}

const char *Fl_Preferences_group(Fl_Preferences *prefs, int num_group) {
    return prefs->group(num_group);
}

char Fl_Preferences_group_exists(Fl_Preferences *prefs, const char *key) {
    return prefs->group_exists(key);
}

char Fl_Preferences_delete_group(Fl_Preferences *prefs, const char *group) {
    return prefs->delete_group(group);
}

char Fl_Preferences_delete_all_groups(Fl_Preferences *prefs) {
    return prefs->delete_all_groups();
}

int Fl_Preferences_entries(Fl_Preferences *prefs) {
    return prefs->entries();
}

const char *Fl_Preferences_entry(Fl_Preferences *prefs, int index) {
    return prefs->entry(index);
}

char Fl_Preferences_entry_exists(Fl_Preferences *prefs, const char *key) {
    return prefs->entry_exists(key);
}

char Fl_Preferences_delete_entry(Fl_Preferences *prefs, const char *entry) {
    return prefs->delete_entry(entry);
}

char Fl_Preferences_delete_all_entries(Fl_Preferences *prefs) {
    return prefs->delete_all_entries();
}

char Fl_Preferences_clear(Fl_Preferences *prefs) {
    return prefs->clear();
}

char Fl_Preferences_seti(Fl_Preferences *prefs, const char *entry, int value) {
    return prefs->set(entry, value);
}

char Fl_Preferences_setf(
    Fl_Preferences *prefs, const char *entry, float value
) {
    return prefs->set(entry, value);
}

char Fl_Preferences_setfp(
    Fl_Preferences *prefs, const char *entry, float value, int precision
) {
    return prefs->set(entry, value, precision);
}

char Fl_Preferences_setd(
    Fl_Preferences *prefs, const char *entry, double value
) {
    return prefs->set(entry, value);
}

char Fl_Preferences_setdp(
    Fl_Preferences *prefs, const char *entry, double value, int precision
) {
    return prefs->set(entry, value, precision);
}

char Fl_Preferences_sets(
    Fl_Preferences *prefs, const char *entry, const char *value
) {
    return prefs->set(entry, value);
}

char Fl_Preferences_setv(
    Fl_Preferences *prefs, const char *entry, const void *value, int size
) {
    return prefs->set(entry, value, size);
}

char Fl_Preferences_geti(
    Fl_Preferences *prefs, const char *entry, int *value, int defaultValue
) {
    return prefs->get(entry, *value, defaultValue);
}

char Fl_Preferences_getf(
    Fl_Preferences *prefs, const char *entry, float *value, float defaultValue
) {
    return prefs->get(entry, *value, defaultValue);
}

char Fl_Preferences_getd(
    Fl_Preferences *prefs, const char *entry, double *value, double defaultValue
) {
    return prefs->get(entry, *value, defaultValue);
}

char Fl_Preferences_gets(
    Fl_Preferences *prefs,
    const char *entry,
    char *value,
    const char *defaultValue,
    int maxSize
) {
    return prefs->get(entry, value, defaultValue, maxSize);
}

char Fl_Preferences_getv(
    Fl_Preferences *prefs,
    const char *entry,
    void *value,
    const void *defaultValue,
    int defaultSize,
    int maxSize
) {
    return prefs->get(entry, value, defaultValue, defaultSize, maxSize);
}

char Fl_Preferences_getv2(
    Fl_Preferences *prefs,
    const char *entry,
    void *value,
    const void *defaultValue,
    int defaultSize,
    int *size
) {
    return prefs->get(entry, value, defaultValue, defaultSize, size);
}

int Fl_Preferences_size(Fl_Preferences *prefs, const char *entry) {
    return prefs->size(entry);
}