/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _LOG_H_
#define _LOG_H_

#define LOG_ENABLE_ERROR    1
#define LOG_ENABLE_WARNING  1
#define LOG_ENABLE_DEBUG    1

#if LOG_ENABLE_ERROR

#define CUDAM_ERROR_MESSAGE(...) \
{\
fprintf(stderr, "\033[101m\033[97m CUDAM Error \033[0m ");\
fprintf(stderr, __VA_ARGS__);\
fprintf(stderr, "\n");\
fflush(stderr);\
}

#define CUDAM_ERROR(...) \
{\
fprintf(stderr, "\033[101m\033[97m CUDAM Error \033[0m ");\
fprintf(stderr, __VA_ARGS__);\
fprintf(stderr, ";\n\
  \033[33mfile:\033[0m       %s;\n\
  \033[33mfunction:\033[0m   %s;\n\
  \033[33mline:\033[0m       %d;\n", __FILE__, __func__, __LINE__);\
fflush(stderr);\
}
#else

#define CUDAM_ERROR_MESSAGE(...)
#define CUDAM_ERROR(...)

#endif\


#if LOG_ENABLE_WARNING

#define CUDAM_WARNING_MESSAGE(...) \
{\
fprintf(stdout, "\033[103m\033[97m CUDAM Warning \033[0m ");\
fprintf(stdout, __VA_ARGS__);\
fprintf(stdout, "\n");\
}

#define CUDAM_WARNING(...) \
{\
fprintf(stdout, "\033[103m\033[97m CUDAM Warning \033[0m ");\
fprintf(stdout, __VA_ARGS__);\
fprintf(stdout, ";\n\
  \033[33mfile:\033[0m       %s;\n\
  \033[33mfunction:\033[0m   %s;\n\
  \033[33mline:\033[0m       %d;\n", __FILE__, __func__, __LINE__);\
fflush(stdout);\
}

#else

#define CUDAM_WARNING_MESSAGE(...)
#define CUDAM_WARNING(...)

#endif


#if LOG_ENABLE_DEBUG

#define CUDAM_DEBUG_MESSAGE_WITHOUT_NEWLINE(is_last_call, ...) \
{\
fprintf(stdout, "\r\033[104m\033[97m CUDAM Debug \033[0m ");\
fprintf(stdout, __VA_ARGS__);\
if(is_last_call){ \
fprintf(stdout, "\n");\
}\
}

#define CUDAM_DEBUG_MESSAGE(...) \
{\
fprintf(stdout, "\033[104m\033[97m CUDAM Debug \033[0m ");\
fprintf(stdout, __VA_ARGS__);\
fprintf(stdout, "\n");\
}

#define CUDAM_DEBUG(...) \
{\
fprintf(stdout, "\033[104m\033[97m CUDAM Debug \033[0m ");\
fprintf(stdout, __VA_ARGS__);\
fprintf(stdout, ";\n\
  \033[33mfile:\033[0m       %s;\n\
  \033[33mfunction:\033[0m   %s;\n\
  \033[33mline:\033[0m       %d;\n", __FILE__, __func__, __LINE__);\
}

#else
#define CUDAM_DEBUG_MESSAGE_WITHOUT_NEWLINE(...)
#define CUDAM_DEBUG_MESSAGE(...)
#define CUDAM_DEBUG(...)

#endif

#endif

