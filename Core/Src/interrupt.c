#include "interrupt.h".h"

uint32_t enter_critical_section(uint32_t priority) {
    uint32_t old_basepri = __get_BASEPRI();
    __set_BASEPRI(priority);
    return old_basepri;
}

void exit_critical_section(uint32_t old_basepri) {
    __set_BASEPRI(old_basepri);
}
