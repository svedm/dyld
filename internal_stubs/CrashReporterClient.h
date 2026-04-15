#ifndef _CRASHREPORTERCLIENT_H_
#define _CRASHREPORTERCLIENT_H_
#define CRSetCrashLogMessage(msg)
#define CRSetCrashLogMessage2(msg)
#define CRGetCrashLogMessage() ""
#define CRASHREPORTER_ANNOTATIONS_SECTION "__crash_info"
#define CRASHREPORTER_ANNOTATIONS_VERSION 5
struct crashreporter_annotations_t {
    unsigned long version; const char *message;
    unsigned long long signature_string; unsigned long long backtrace;
    const char *message2; unsigned long long thread;
    unsigned long long dialog_mode; unsigned long long abort_cause;
};
#endif
