//
// Created by davidng on 6/18/24.
//

#ifndef FIRSTPROJECT_LOGGING_H
#define FIRSTPROJECT_LOGGING_H

#include <android/log.h>

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "LOG", __VA_ARGS__)

#endif //FIRSTPROJECT_LOGGING_H
