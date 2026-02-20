/**
 * @file OSAL_Core.h
 * @brief OSAL core: delay/sleep, random, Serial/print (platform abstraction).
 */

#ifndef OSAL_OSAL_CORE_H
#define OSAL_OSAL_CORE_H

#include <StandardDefines.h>

#ifdef ARDUINO
#include <Thread.h>
#include <Arduino.h>

inline Void OSAL_DelayMs(ULong ms) {
    Thread::Sleep(static_cast<unsigned long>(ms));
}

/** Elapsed milliseconds since boot (e.g. Arduino millis()). */
inline ULong OSAL_GetMillis(void) {
    return static_cast<ULong>(millis());
}

inline ULong OSAL_GenerateConnectionId(void) {
    return static_cast<ULong>(random(1, 2147483647));
}

/** Platform print (e.g. Serial.println on Arduino). */
inline Void OSAL_Println(const StdString& s) {
    Serial.println(s.c_str());
}

#else
#error "OSAL_Core.h: only ARDUINO platform is implemented"
#endif

#endif /* OSAL_OSAL_CORE_H */
