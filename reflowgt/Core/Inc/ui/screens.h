#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _groups_t {
    lv_group_t *Enc;
} groups_t;

extern groups_t groups;

void ui_create_groups();

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *reflow_m;
    lv_obj_t *sp_m;
    lv_obj_t *reflow_chart;
    lv_obj_t *input;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *drop_down_list;
    lv_obj_t *load_data;
    lv_obj_t *delete_data;
    lv_obj_t *save_data;
    lv_obj_t *save_data_1;
    lv_obj_t *t1;
    lv_obj_t *t2;
    lv_obj_t *t3;
    lv_obj_t *t4;
    lv_obj_t *time1;
    lv_obj_t *time2;
    lv_obj_t *time3;
    lv_obj_t *time4;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *t1_label;
    lv_obj_t *t2_label;
    lv_obj_t *t3_label;
    lv_obj_t *t4_label;
    lv_obj_t *time1_label;
    lv_obj_t *time2_label;
    lv_obj_t *time3_label;
    lv_obj_t *time4_label;
    lv_obj_t *mode2_chart;
    lv_obj_t *sp_text;
    lv_obj_t *pv_text;
    lv_obj_t *mode1_chart;
    lv_obj_t *sp_text_1;
    lv_obj_t *pv_text_1;
    lv_obj_t *reflow_status;
    lv_obj_t *user_input;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_REFLOW_M = 2,
    SCREEN_ID_SP_M = 3,
    SCREEN_ID_REFLOW_CHART = 4,
    SCREEN_ID_INPUT = 5,
};

void create_screen_main();
void tick_screen_main();

void create_screen_reflow_m();
void tick_screen_reflow_m();

void create_screen_sp_m();
void tick_screen_sp_m();

void create_screen_reflow_chart();
void tick_screen_reflow_chart();

void create_screen_input();
void tick_screen_input();

void create_user_widget_flyingwindow(lv_obj_t *parent_obj, int startWidgetIndex);
void tick_user_widget_flyingwindow(int startWidgetIndex);

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/