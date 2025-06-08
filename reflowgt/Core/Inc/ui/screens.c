#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"
#include "main.h"
#include "fatfs.h"
uint16_t SP_data = 30, SP_data_temp = 30, data_count = 0;
uint16_t temp_data[] = {30, 180, 180, 250, 250};
uint16_t time_data[] = {1, 50, 100, 150, 180};
uint32_t prev_recorded = 0;
int enc_data = 0, index_now = 0;
float time_from_start = 0;
static lv_timer_t *encoder_timer = NULL;
static lv_timer_t *chart_timer = NULL;
char selected_file[16];
lv_chart_series_t * ser = NULL, *ser2 = NULL, *ser_sp = NULL, *ser_pv = NULL;

void set_enc_data(int a){
    get_enc_data();
	enc_data = a;
}

int get_enc_data() {
    static int prev_data = 0;
    int pulse = (TIM2->CNT) >> 2;
    int selisih = pulse - prev_data;

    if (selisih > 536870912) {
    	enc_data += selisih - 1073741824;
    }
    else if (selisih < -536870912) {
    	enc_data += selisih + 1073741824;
    }
    else {
    	enc_data += selisih;
    }

    prev_data = pulse;
    return enc_data;
}

#include <string.h>

groups_t groups;
static bool groups_created = false;

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_main(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        // group: Enc
        lv_group_remove_all_objs(groups.Enc);
        lv_group_add_obj(groups.Enc, objects.obj0);
        lv_group_add_obj(groups.Enc, objects.obj1);
    }
}

static void event_handler_cb_reflow_m_reflow_m(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        // group: Enc
        lv_group_remove_all_objs(groups.Enc);
        lv_group_add_obj(groups.Enc, objects.obj2);
        lv_group_add_obj(groups.Enc, objects.drop_down_list);
        lv_group_add_obj(groups.Enc, objects.load_data);
        lv_group_add_obj(groups.Enc, objects.delete_data);
        lv_group_add_obj(groups.Enc, objects.save_data);
        lv_group_add_obj(groups.Enc, objects.save_data_1);
        lv_group_add_obj(groups.Enc, objects.t1);
        lv_group_add_obj(groups.Enc, objects.t2);
        lv_group_add_obj(groups.Enc, objects.t3);
        lv_group_add_obj(groups.Enc, objects.t4);
        lv_group_add_obj(groups.Enc, objects.time1);
        lv_group_add_obj(groups.Enc, objects.time2);
        lv_group_add_obj(groups.Enc, objects.time3);
        lv_group_add_obj(groups.Enc, objects.time4);
        lv_group_add_obj(groups.Enc, objects.obj3);
    }
}

static void event_handler_checked_cb_reflow_m_t1(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_change_data(e);
    }
}

static void event_handler_unchecked_cb_reflow_m_t1(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_done_changed_data(e);
    }
}

static void event_handler_checked_cb_reflow_m_t2(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_change_data(e);
    }
}

static void event_handler_unchecked_cb_reflow_m_t2(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_done_changed_data(e);
    }
}

static void event_handler_checked_cb_reflow_m_t3(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_change_data(e);
    }
}

static void event_handler_unchecked_cb_reflow_m_t3(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_done_changed_data(e);
    }
}

static void event_handler_checked_cb_reflow_m_t4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_change_data(e);
    }
}

static void event_handler_unchecked_cb_reflow_m_t4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_done_changed_data(e);
    }
}

static void event_handler_checked_cb_reflow_m_time1(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_change_data(e);
    }
}

static void event_handler_unchecked_cb_reflow_m_time1(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_done_changed_data(e);
    }
}

static void event_handler_checked_cb_reflow_m_time2(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_change_data(e);
    }
}

static void event_handler_unchecked_cb_reflow_m_time2(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_done_changed_data(e);
    }
}

static void event_handler_checked_cb_reflow_m_time3(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_change_data(e);
    }
}

static void event_handler_unchecked_cb_reflow_m_time3(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_done_changed_data(e);
    }
}

static void event_handler_checked_cb_reflow_m_time4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_change_data(e);
    }
}

static void event_handler_unchecked_cb_reflow_m_time4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_done_changed_data(e);
    }
}

static void event_handler_cb_sp_m_sp_m(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        // group: Enc
        lv_group_remove_all_objs(groups.Enc);
        lv_group_add_obj(groups.Enc, objects.obj4);
        lv_group_add_obj(groups.Enc, objects.obj5);
    }
}

static void event_handler_unchecked_cb_sp_m_obj4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_sp_btn_released(e);
    }
}

static void event_handler_checked_cb_sp_m_obj4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_sp_btn_pressed(e);
    }
}

static void event_handler_cb_reflow_chart_reflow_chart(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        // group: Enc
        lv_group_remove_all_objs(groups.Enc);
        lv_group_add_obj(groups.Enc, objects.obj6);
    }
}

static void event_handler_cb_input_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        // group: Enc
        lv_group_remove_all_objs(groups.Enc);
        lv_group_add_obj(groups.Enc, objects.obj7);
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_event_cb(obj, event_handler_cb_main_main, LV_EVENT_ALL, 0);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 20, 95);
            lv_obj_set_size(obj, 130, 50);
            lv_obj_add_event_cb(obj, action_reflow_mode, LV_EVENT_RELEASED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff21eaf3), LV_PART_MAIN | LV_STATE_FOCUSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Reflow Mode");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 180, 95);
            lv_obj_set_size(obj, 130, 50);
            lv_obj_add_event_cb(obj, action_sp_mode, LV_EVENT_RELEASED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff21eaf3), LV_PART_MAIN | LV_STATE_FOCUSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "SetPoint Mode");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_main() {
}

void create_screen_reflow_m() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.reflow_m = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_event_cb(obj, event_handler_cb_reflow_m_reflow_m, LV_EVENT_ALL, 0);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 4, 5);
            lv_obj_set_size(obj, 30, 30);
            lv_obj_add_event_cb(obj, action_nav, LV_EVENT_RELEASED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "<-");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Drop_down_list
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.drop_down_list = obj;
            lv_obj_set_pos(obj, 42, 7);
            lv_obj_set_size(obj, 167, 28);
            lv_dropdown_set_options(obj, "-- Select --");
            lv_obj_add_event_cb(obj, action_load_list, LV_EVENT_VALUE_CHANGED, (void *)0);
        }
        {
            // Load_Data
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.load_data = obj;
            lv_obj_set_pos(obj, 215, 8);
            lv_obj_set_size(obj, 83, 26);
            lv_obj_add_event_cb(obj, action_load_dropdown, LV_EVENT_RELEASED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "LOAD");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Delete_Data
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.delete_data = obj;
            lv_obj_set_pos(obj, 43, 40);
            lv_obj_set_size(obj, 83, 26);
            lv_obj_add_event_cb(obj, action_delete_data, LV_EVENT_RELEASED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "DELETE");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Save_data
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_data = obj;
            lv_obj_set_pos(obj, 129, 40);
            lv_obj_set_size(obj, 83, 26);
            lv_obj_add_event_cb(obj, action_update_data, LV_EVENT_RELEASED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "UPDATE");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Save_data_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_data_1 = obj;
            lv_obj_set_pos(obj, 215, 40);
            lv_obj_set_size(obj, 83, 26);
            lv_obj_add_event_cb(obj, action_nav, LV_EVENT_PRESSED, (void *)3);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "ADD DATA");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // T1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.t1 = obj;
            lv_obj_set_pos(obj, 14, 118);
            lv_obj_set_size(obj, 64, 27);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_reflow_m_t1, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_reflow_m_t1, LV_EVENT_VALUE_CHANGED, (void *)1);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // T1_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.t1_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "180°C");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // T2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.t2 = obj;
            lv_obj_set_pos(obj, 90, 118);
            lv_obj_set_size(obj, 64, 27);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_reflow_m_t2, LV_EVENT_VALUE_CHANGED, (void *)2);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_reflow_m_t2, LV_EVENT_VALUE_CHANGED, (void *)2);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // T2_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.t2_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "180°C");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // T3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.t3 = obj;
            lv_obj_set_pos(obj, 162, 118);
            lv_obj_set_size(obj, 64, 27);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_reflow_m_t3, LV_EVENT_VALUE_CHANGED, (void *)3);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_reflow_m_t3, LV_EVENT_VALUE_CHANGED, (void *)3);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // T3_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.t3_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "250°C");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // T4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.t4 = obj;
            lv_obj_set_pos(obj, 238, 118);
            lv_obj_set_size(obj, 64, 27);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_reflow_m_t4, LV_EVENT_VALUE_CHANGED, (void *)4);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_reflow_m_t4, LV_EVENT_VALUE_CHANGED, (void *)4);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // T4_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.t4_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "250°C");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // time1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.time1 = obj;
            lv_obj_set_pos(obj, 14, 175);
            lv_obj_set_size(obj, 64, 27);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_reflow_m_time1, LV_EVENT_VALUE_CHANGED, (void *)5);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_reflow_m_time1, LV_EVENT_VALUE_CHANGED, (void *)5);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // time1_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.time1_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "50s");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // time2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.time2 = obj;
            lv_obj_set_pos(obj, 90, 175);
            lv_obj_set_size(obj, 64, 27);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_reflow_m_time2, LV_EVENT_VALUE_CHANGED, (void *)6);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_reflow_m_time2, LV_EVENT_VALUE_CHANGED, (void *)6);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // time2_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.time2_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "100s");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // time3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.time3 = obj;
            lv_obj_set_pos(obj, 162, 175);
            lv_obj_set_size(obj, 64, 27);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_reflow_m_time3, LV_EVENT_VALUE_CHANGED, (void *)7);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_reflow_m_time3, LV_EVENT_VALUE_CHANGED, (void *)7);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // time3_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.time3_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "150s");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // time4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.time4 = obj;
            lv_obj_set_pos(obj, 238, 175);
            lv_obj_set_size(obj, 64, 27);
            lv_obj_add_event_cb(obj, event_handler_checked_cb_reflow_m_time4, LV_EVENT_VALUE_CHANGED, (void *)8);
            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_reflow_m_time4, LV_EVENT_VALUE_CHANGED, (void *)8);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // time4_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.time4_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "180s");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 283, 208);
            lv_obj_set_size(obj, 30, 30);
            lv_obj_add_event_cb(obj, action_nav, LV_EVENT_RELEASED, (void *)2);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "->");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 113, 98);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Temperature");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 142, 158);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Time");
        }
    }
}

void tick_screen_reflow_m() {
}

void create_screen_sp_m() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.sp_m = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_event_cb(obj, event_handler_cb_sp_m_sp_m, LV_EVENT_ALL, 0);
    {
        lv_obj_t *parent_obj = obj;
        {
            // mode2_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.mode2_chart = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 26, 16);
                    lv_obj_set_size(obj, 100, 21);
                    lv_obj_add_event_cb(obj, event_handler_unchecked_cb_sp_m_obj4, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_event_cb(obj, event_handler_checked_cb_sp_m_obj4, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // SP_text
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.sp_text = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "SP = 30°C");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // Pv_text
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.pv_text = obj;
                    lv_obj_set_pos(obj, 27, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "T = 0°C | t = 0s");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 4, 5);
            lv_obj_set_size(obj, 30, 30);
            lv_obj_add_event_cb(obj, action_nav, LV_EVENT_RELEASED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "<-");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_sp_m() {
}

void create_screen_reflow_chart() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.reflow_chart = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_event_cb(obj, event_handler_cb_reflow_chart_reflow_chart, LV_EVENT_ALL, 0);
    {
        lv_obj_t *parent_obj = obj;
        {
            // mode1_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.mode1_chart = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 26, 16);
                    lv_obj_set_size(obj, 100, 21);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // SP_text_1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.sp_text_1 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "SP = 30°C");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // Pv_text_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.pv_text_1 = obj;
                    lv_obj_set_pos(obj, 27, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "T = 0°C | t = 0s");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // reflow_status
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.reflow_status = obj;
                    lv_obj_set_pos(obj, 10, 10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "___________");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffa500), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 4, 5);
            lv_obj_set_size(obj, 30, 30);
            lv_obj_add_event_cb(obj, action_nav, LV_EVENT_RELEASED, (void *)11);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "<-");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_reflow_chart() {
}

void create_screen_input() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.input = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_event_cb(obj, event_handler_cb_input_input, LV_EVENT_ALL, 0);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_msgbox_create(parent_obj);
            lv_obj_set_pos(obj, 36, 24);
            lv_obj_set_size(obj, 249, 59);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 69, 34);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Masukkan Nama Profile : ");
                }
                {
                    // User_input
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.user_input = obj;
                    lv_obj_set_pos(obj, 114, 49);
                    lv_obj_set_size(obj, 247, 25);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                }
            }
        }
        {
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 0, 120);
            lv_obj_set_size(obj, 320, 120);
            lv_obj_add_event_cb(obj, action_save_data, LV_EVENT_READY, (void *)0);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_keyboard_set_textarea(objects.obj7, objects.user_input);
}

void tick_screen_input() {
}

void create_user_widget_flyingwindow(lv_obj_t *parent_obj, int startWidgetIndex) {
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_msgbox_create(parent_obj);
            lv_obj_set_pos(obj, 36, 45);
            lv_obj_set_size(obj, 249, 59);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // User_input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 44, 67);
            lv_obj_set_size(obj, 227, 25);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 44, 51);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Masukkan Nama Profile : ");
        }
        {
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
            lv_obj_set_pos(obj, 0, 104);
            lv_obj_set_size(obj, 320, 136);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_keyboard_set_textarea(((lv_obj_t **)&objects)[startWidgetIndex + 1], ((lv_obj_t **)&objects)[startWidgetIndex + 0]);
}

void tick_user_widget_flyingwindow(int startWidgetIndex) {
}


void ui_create_groups() {
    if (!groups_created) {
        groups.Enc = lv_group_create();
        groups_created = true;
    }
}

void create_screens() {
    ui_create_groups();
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_reflow_m();
    create_screen_sp_m();
    create_screen_reflow_chart();
    create_screen_input();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_reflow_m,
    tick_screen_sp_m,
    tick_screen_reflow_chart,
    tick_screen_input,
    0,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}


static void add_data(lv_timer_t * t)
{
    lv_obj_t * chart = lv_timer_get_user_data(t);
    lv_chart_series_t * ser_data = lv_chart_get_series_next(chart, NULL);
    lv_chart_series_t * ser2_data = lv_chart_get_series_next(chart, ser);

    uint16_t max_points = lv_chart_get_point_count(chart);
    uint16_t sp = adc2Celcius();

    lv_chart_set_next_value(chart, ser_data, sp);
    lv_chart_set_next_value(chart, ser2_data, SP_data);
    
    uint16_t p = lv_chart_get_point_count(chart);
    uint16_t s = lv_chart_get_x_start_point(chart, ser);
    int32_t * a = lv_chart_get_y_array(chart, ser);

    a[(s + 1) % p] = LV_CHART_POINT_NONE;
    a[(s + 2) % p] = LV_CHART_POINT_NONE;
    a[(s + 3) % p] = LV_CHART_POINT_NONE;

    data_count++;
    if (data_count >= max_points) {
        lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_SHIFT);
        data_count = 0;
    }
    
    time_from_start += (float)GetElapsedTimems(prev_recorded)/1000.0;
    prev_recorded = uwTick;
    char buf[40];
    snprintf(buf, sizeof(buf), "T = %d°C | t = %.1fs", sp, time_from_start);
    lv_label_set_text(objects.pv_text, buf);
    
    
    

    lv_chart_refresh(chart);
}

void action_reflow_mode(lv_event_t *e) {
	lv_scr_load(objects.reflow_m);
}

void action_sp_mode(lv_event_t * e){
    time_from_start = 0;
    lv_group_remove_all_objs(groups.Enc);
	lv_scr_load(objects.sp_m);
	
	lv_chart_set_update_mode(objects.mode2_chart, LV_CHART_UPDATE_MODE_CIRCULAR);

    lv_obj_set_size(objects.mode2_chart, 315, 240);
    lv_obj_align(objects.mode2_chart, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_chart_set_point_count(objects.mode2_chart, 60);

    lv_chart_set_div_line_count(objects.mode2_chart, 11, 6);
    lv_obj_set_style_bg_opa(objects.mode2_chart, LV_OPA_20, 0);
    lv_obj_set_style_bg_color(objects.mode2_chart, lv_color_make(200, 200, 200), 0);

    lv_obj_clear_flag(objects.mode2_chart, LV_OBJ_FLAG_SCROLLABLE);

    // Range awal
    lv_chart_set_range(objects.mode2_chart, LV_CHART_AXIS_PRIMARY_Y, 20, 260);
    if(ser != NULL){
        lv_chart_remove_series(objects.mode2_chart, ser);
        lv_chart_remove_series(objects.mode2_chart, ser2);
    }
    
	ser = lv_chart_add_series(objects.mode2_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    ser2 = lv_chart_add_series(objects.mode2_chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);

    prev_recorded = uwTick;
    temp_data[0] = adc2Celcius();
    compute_PI(temp_data[0], temp_data[0], 0,0,0);
    data_count = 0;
    
    chart_timer = lv_timer_create(add_data, 1000, objects.mode2_chart);
    if ((htim3.Instance->CR1 & TIM_CR1_CEN) == 0) {
		  HAL_TIM_Base_Start_IT(&htim3); 
        
    }
}

static void update_sp_txt(lv_timer_t *timer){
    SP_data_temp = get_enc_data();
    char buf[40];
    snprintf(buf, sizeof(buf), "SP = %d°C", SP_data_temp);
    lv_label_set_text(objects.sp_text, buf);
}

void action_sp_btn_pressed(lv_event_t *e) {
    set_enc_data(SP_data);
    encoder_timer = lv_timer_create(update_sp_txt, 100, NULL);
    lv_group_focus_freeze(groups.Enc, true);
}

void action_sp_btn_released(lv_event_t *e) {
    lv_timer_del(encoder_timer);
    encoder_timer = NULL;
    SP_data = SP_data_temp;
    lv_group_focus_freeze(groups.Enc, false);
    
}

typedef struct {
    uint8_t btn_id;
    lv_obj_t *label_obj;
} TimerData;

TimerData timer_data;

static void update_sp_data(lv_timer_t *timer) {
    SP_data_temp = get_enc_data();
    char buf[40];

    if (timer_data.btn_id > 4) {
        snprintf(buf, sizeof(buf), "%ds", SP_data_temp);
    } else {
        snprintf(buf, sizeof(buf), "%d°C", SP_data_temp);
    }

    lv_label_set_text(timer_data.label_obj, buf);
    
}

void action_change_data(lv_event_t *e) {
    uint8_t btn_id = (uint8_t)lv_event_get_user_data(e);
    lv_obj_t *btn_obj = lv_event_get_target(e);
    lv_obj_t *label_obj = lv_obj_get_child(btn_obj, NULL);
    
    if (btn_id > 4) {
        set_enc_data(time_data[btn_id - 4]);
    } else {
        set_enc_data(temp_data[btn_id]);
    }
    timer_data.btn_id = btn_id;
    timer_data.label_obj = label_obj;
    encoder_timer = lv_timer_create(update_sp_data, 100, NULL);
    lv_group_focus_freeze(groups.Enc, true);
}

void action_done_changed_data(lv_event_t *e) {
    uint8_t btn_id = (uint8_t)lv_event_get_user_data(e);
    if(btn_id > 4){
        time_data[btn_id - 4] = SP_data_temp;
    }
    else{
        temp_data[btn_id] = SP_data_temp;
    }
    lv_timer_del(encoder_timer);
    encoder_timer = NULL;
    lv_group_focus_freeze(groups.Enc, false);
}

void update_reflow_btn_data(lv_obj_t *obj, int data, bool temp){
    char buf[10];
    if(temp){
        snprintf(buf, sizeof(buf), "%d°C", data);
        lv_label_set_text(obj, buf);
    }
    else{
        snprintf(buf, sizeof(buf), "%ds", data);
        lv_label_set_text(obj, buf);
    }
    
}

void reload_data(){
    read_data(&temp_data[1], &temp_data[2], &temp_data[3], &temp_data[4], &time_data[1], &time_data[2], &time_data[3], &time_data[4], selected_file);
    update_reflow_btn_data(objects.t1_label, temp_data[1], 1);
    update_reflow_btn_data(objects.t2_label, temp_data[2], 1);
    update_reflow_btn_data(objects.t3_label, temp_data[3], 1);
    update_reflow_btn_data(objects.t4_label, temp_data[4], 1);
    update_reflow_btn_data(objects.time1_label, time_data[1], 0);
    update_reflow_btn_data(objects.time2_label, time_data[2], 0);
    update_reflow_btn_data(objects.time3_label, time_data[3], 0);
    update_reflow_btn_data(objects.time4_label, time_data[4], 0);
}

void action_load_list(lv_event_t *e) {
    // TODO: Implement action load_dropdown here
    lv_obj_t * dropdown = lv_event_get_target(e);
    lv_dropdown_get_selected_str(dropdown, selected_file, sizeof(selected_file));
    reload_data();
}

void action_load_dropdown(lv_event_t *e) {
    char file_list[128];
    FRESULT fres = list_txt_files(file_list, sizeof(file_list));
    if (fres == FR_OK) {
        lv_dropdown_set_options(objects.drop_down_list, file_list);
    }
    else{
        make_flying_win("Pastikan Kabel dan SD Card sudah terpasang dengan benar");
    }
    if(lv_dropdown_get_option_count(objects.drop_down_list) > 0){
        lv_dropdown_set_selected(objects.drop_down_list, 0, LV_ANIM_OFF);
    }
}

static void add_data_mode1(lv_timer_t * t)
{
    lv_obj_t * chart = lv_timer_get_user_data(t);
    lv_chart_series_t * ser = lv_chart_get_series_next(chart, NULL);
    lv_chart_series_t * ser2 = lv_chart_get_series_next(chart, ser);

    uint16_t max_points = lv_chart_get_point_count(chart);
    uint16_t pv = adc2Celcius();
    uint16_t s = lv_chart_get_x_start_point(chart, ser);

    data_count++;
    if (data_count >= max_points) {
        lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_SHIFT);
        data_count = 0;
    }
    
    char buf[40];
    int num_points = sizeof(time_data) / sizeof(time_data[0]);
    time_from_start += (float)GetElapsedTimems(prev_recorded)/1000.0;
    index_now = 0;
    for(index_now = 0; index_now < num_points; index_now++){
        if(time_from_start <= time_data[index_now]) break;
    }
    switch (index_now) {
	  case 1:
	    lv_label_set_text(objects.reflow_status, "PREHEAT");
	    lv_obj_set_style_bg_color(objects.reflow_status, lv_color_hex(0xFFA500), LV_PART_MAIN);
	  break;
	  
	  case 2:
	    lv_label_set_text(objects.reflow_status, "SOAK");
	    lv_obj_set_style_bg_color(objects.reflow_status, lv_color_hex(0xFFFF00), LV_PART_MAIN);
	  break;
	  
	  case 3:
	    lv_label_set_text(objects.reflow_status, "REFLOW");
	    lv_obj_set_style_bg_color(objects.reflow_status, lv_color_hex(0xFF0000), LV_PART_MAIN);
	  break;
	  
	  case 4:
	    lv_label_set_text(objects.reflow_status, "TAL");
	    lv_obj_set_style_bg_color(objects.reflow_status, lv_color_hex(0xFF0000), LV_PART_MAIN);
	  break;
	  
	  case 5:
	    lv_label_set_text(objects.reflow_status, "COOLING");
	    lv_obj_set_style_bg_color(objects.reflow_status, lv_color_hex(0x0000FF), LV_PART_MAIN);
	   // lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_SHIFT);
	  break;
    }
        
    if (index_now >= num_points) {
        snprintf(buf, sizeof(buf), "SP = -");
        SP_data = 0;
        if ((htim3.Instance->CR1 & TIM_CR1_CEN) == 1) {
		    HAL_TIM_Base_Stop_IT(&htim3);
	    }
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
        lv_chart_set_next_value(chart, ser2, 25);
    } else {
        int x0 = time_data[index_now - 1], y0 = temp_data[index_now - 1];
        int x1 = time_data[index_now], y1 = temp_data[index_now];
        
        SP_data = y0 + (time_from_start - x0) * (y1 - y0) / (x1 - x0);
        snprintf(buf, sizeof(buf), "SP = %d°C", SP_data);
    }
    lv_chart_set_x_start_point(objects.mode1_chart, ser, (int)time_from_start/2);
    lv_chart_set_next_value(chart, ser, pv);
    
    prev_recorded = uwTick;
    lv_label_set_text(objects.sp_text_1, buf);
    
    snprintf(buf, sizeof(buf), "T = %u°C | t = %.1fs", pv, time_from_start);
    lv_label_set_text(objects.pv_text_1, buf);
    lv_chart_refresh(chart);
}

void back_to_home(){
    if(chart_timer != NULL){
        lv_timer_del(chart_timer);
        chart_timer = NULL;
    } 
    if ((htim3.Instance->CR1 & TIM_CR1_CEN) == 1) {
        HAL_TIM_Base_Stop_IT(&htim3);
    }
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
    // lv_scr_load(objects.main);
    if (lv_scr_act() != objects.main) {
        lv_scr_load(objects.main);
    }
}

void action_nav(lv_event_t *e) {
    // TODO: Implement action nav here
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
    uint8_t destination_sc_id = (uint8_t)lv_event_get_user_data(e);
    if(chart_timer != NULL){
        lv_timer_del(chart_timer);
        chart_timer = NULL;
        if ((htim3.Instance->CR1 & TIM_CR1_CEN) == 1) {
		    HAL_TIM_Base_Stop_IT(&htim3);
	    }
    } 
    if(destination_sc_id == 0){
        if ((htim3.Instance->CR1 & TIM_CR1_CEN) == 1) {
		    HAL_TIM_Base_Stop_IT(&htim3);
	  }
	  lv_scr_load(objects.main);
    } 
    else if(destination_sc_id == 1 || destination_sc_id == 11){
        lv_scr_load(objects.reflow_m);
        action_load_dropdown(NULL);
        if ((htim3.Instance->CR1 & TIM_CR1_CEN) == 1) {
		    HAL_TIM_Base_Stop_IT(&htim3);
	    }
	    if(destination_sc_id == 11){
	        lv_dropdown_set_selected(objects.drop_down_list, lv_dropdown_get_option_index(objects.drop_down_list, selected_file),LV_ANIM_OFF);
	    }
    }
    else if(destination_sc_id == 2 ){
        time_from_start = 0;
        temp_data[0] = adc2Celcius();
        compute_PI(temp_data[0], temp_data[0], 0,0,0);
        lv_scr_load(objects.reflow_chart);
        lv_chart_set_type(objects.mode1_chart, LV_CHART_TYPE_LINE);
        lv_chart_set_update_mode(objects.mode1_chart, LV_CHART_UPDATE_MODE_CIRCULAR);

        lv_obj_align(objects.mode1_chart, LV_ALIGN_TOP_LEFT, 0, 0);
        int total_data_displayed = time_data[4]/2 + ((time_data[4]/2)/4);
        lv_chart_set_point_count(objects.mode1_chart, total_data_displayed);
        // lv_chart_set_point_count(objects.mode1_chart, time_data[4]+10);
    
        lv_chart_set_div_line_count(objects.mode1_chart, 11, 6);
        lv_obj_set_style_bg_opa(objects.mode1_chart, LV_OPA_20, 0);
        lv_obj_set_style_bg_color(objects.mode1_chart, lv_color_make(200, 200, 200), 0);
    
        lv_obj_clear_flag(objects.mode1_chart, LV_OBJ_FLAG_SCROLLABLE);
    
        if(ser_sp != NULL){
            lv_chart_remove_series(objects.mode1_chart, ser_sp);
            lv_chart_remove_series(objects.mode1_chart, ser_pv);
        }
    
        lv_chart_set_range(objects.mode1_chart, LV_CHART_AXIS_PRIMARY_Y, 20, 250);
    	ser_pv = lv_chart_add_series(objects.mode1_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
        ser_sp = lv_chart_add_series(objects.mode1_chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);
    
        int num_points = sizeof(time_data) / sizeof(time_data[0]);
    
        int b = 1;
        lv_chart_set_x_start_point(objects.mode1_chart, ser_sp, 1);
        for (int a = 1; ; a+=2) {
            if (b < num_points && a <= time_data[b]) {
                int x0 = time_data[b - 1], y0 = temp_data[b - 1];
                int x1 = time_data[b], y1 = temp_data[b];
    
                int y_interpolasi = y0 + (a - x0) * (y1 - y0) / (x1 - x0);
                lv_chart_set_next_value(objects.mode1_chart, ser_sp, (lv_coord_t)y_interpolasi);
            }
            else if (b >= num_points) {
                lv_chart_set_next_value(objects.mode1_chart, ser_sp, 25);
                break;
            }
            else{
                b++;
            }
        }
        index_now = 0;
        data_count = 0;
        prev_recorded = uwTick;
        chart_timer = lv_timer_create(add_data_mode1, 2000, objects.mode1_chart);
        
        //timer
        if ((htim3.Instance->CR1 & TIM_CR1_CEN) == 0) {
		  HAL_TIM_Base_Start_IT(&htim3); 
        }
    } 
    else if(destination_sc_id == 3){
        lv_group_remove_all_objs(groups.Enc);
        lv_scr_load(objects.input);
        lv_textarea_set_text(objects.user_input, "");
        lv_obj_clear_flag(objects.user_input, LV_OBJ_FLAG_SCROLLABLE);
    } 
}

static void event_cb_flying_win(lv_event_t * e)
{
    lv_group_focus_freeze(groups.Enc, false);
    lv_obj_clean(lv_layer_top());
}

void make_flying_win(const char * message)
{
    lv_obj_t * mbox1 = lv_msgbox_create(lv_layer_top());

    lv_msgbox_add_title(mbox1, message);
    lv_obj_t * btn;
    btn = lv_msgbox_add_footer_button(mbox1, "OK");
    lv_group_add_obj(groups.Enc, btn);
    lv_group_focus_obj(btn);
    lv_group_focus_freeze(groups.Enc, true);
    lv_obj_add_event_cb(btn, event_cb_flying_win, LV_EVENT_RELEASED, NULL);
}

void action_update_data(lv_event_t *e) {
    // TODO: Implement action update_data here
    if(write_data(temp_data[1], temp_data[2], temp_data[3], temp_data[4], time_data[1], time_data[2], time_data[3], time_data[4], selected_file) == 0) make_flying_win("Data telah terupdate");
    else make_flying_win("Pastikan SDcard sudah terpasang");
}

void action_save_data(lv_event_t *e) {
    // TODO: Implement action save_data here
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_READY) {
        const char * input_text = lv_textarea_get_text(objects.user_input);
        write_data(temp_data[1], temp_data[2], temp_data[3], temp_data[4], time_data[1], time_data[2], time_data[3], time_data[4], input_text);
        lv_scr_load(objects.reflow_m);
        lv_group_set_editing(groups.Enc, false);
        action_load_dropdown(NULL);
        strupr(input_text);
        myprintf("result of %s is data = %d\n", input_text, lv_dropdown_get_option_index(objects.drop_down_list, input_text));
        lv_dropdown_set_selected(objects.drop_down_list, lv_dropdown_get_option_index(objects.drop_down_list, input_text),LV_ANIM_OFF);
    }
    
}

void action_delete_data(lv_event_t *e) {
    char file[16];
    lv_dropdown_get_selected_str(objects.drop_down_list, file, 0);
    if(delete_file(file) == 0){
        action_load_dropdown(NULL);
        make_flying_win("Data Berhasil dihapus");
    } 
    else make_flying_win("Mohon ulangi lagi");
    
}

