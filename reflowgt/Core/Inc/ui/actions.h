#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_reflow_mode(lv_event_t * e);
extern void action_sp_mode(lv_event_t * e);
extern void action_sp_btn_pressed(lv_event_t * e);
extern void action_sp_btn_released(lv_event_t * e);
extern void action_change_data(lv_event_t * e);
extern void action_done_changed_data(lv_event_t * e);
extern void action_load_dropdown(lv_event_t * e);
extern void action_load_list(lv_event_t * e);
extern void action_nav(lv_event_t * e);
extern void action_save_data(lv_event_t * e);
extern void action_update_data(lv_event_t * e);
extern void action_delete_data(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/