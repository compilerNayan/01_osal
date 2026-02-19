/**
 * @file OSAL_WiFi.h
 * @brief OSAL WiFi: disconnect, mode, begin, status, soft AP, IP strings (platform abstraction).
 */

#ifndef OSAL_OSAL_WIFI_H
#define OSAL_OSAL_WIFI_H

#include <StandardDefines.h>

/** Platform-agnostic WiFi mode (maps from native WiFiMode_t on Arduino). */
enum class WifiMode { None, Sta, Ap, ApSta };

#ifdef ARDUINO
#include <WiFi.h>
#include <Arduino.h>

inline Void OSAL_WifiDisconnect(void) {
    WiFi.disconnect();
}

inline Void OSAL_WifiSetModeSta(void) {
    WiFi.mode(WIFI_STA);
}

inline Void OSAL_WifiSetModeAp(void) {
    WiFi.mode(WIFI_AP);
}

inline Void OSAL_WifiBegin(const StdString& ssid, const StdString& password) {
    WiFi.begin(ssid.c_str(), password.empty() ? nullptr : password.c_str());
}

inline Bool OSAL_WifiIsConnected(void) {
    return (WiFi.status() == WL_CONNECTED);
}

inline StdString OSAL_WifiGetLocalIpString(void) {
    return StdString(WiFi.localIP().toString().c_str());
}

inline Bool OSAL_WifiStartSoftAp(const StdString& ssid, const char* password) {
    return WiFi.softAP(ssid.c_str(), password);
}

inline StdString OSAL_WifiGetSoftApIpString(void) {
    return StdString(WiFi.softAPIP().toString().c_str());
}

inline Void OSAL_WifiSoftApDisconnect(void) {
    WiFi.softAPdisconnect(true);
}

inline WifiMode OSAL_GetWifiMode(void) {
    WiFiMode_t m = WiFi.getMode();
    if (m == WIFI_AP) return WifiMode::Ap;
    if (m == WIFI_AP_STA) return WifiMode::ApSta;
    if (m == WIFI_STA) return WifiMode::Sta;
    return WifiMode::None;
}

#else
#error "OSAL_WiFi.h: only ARDUINO platform is implemented"
#endif

#endif /* OSAL_OSAL_WIFI_H */
