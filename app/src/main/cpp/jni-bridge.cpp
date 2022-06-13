#include <jni.h>
#include <string>
#include <android/input.h>
#include "AudioEngine.h"

static AudioEngine *audioEngine = new AudioEngine();

extern "C" {

JNIEXPORT jstring JNICALL
Java_com_goofy_goober_wavy_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT void JNICALL
Java_com_goofy_goober_wavy_MainActivity_touchEvent(
        JNIEnv *env,
        jobject obj,
        jint action) {
    switch (action) {
        case AMOTION_EVENT_ACTION_DOWN:
            audioEngine->setToneOn(true);
            break;
        case AMOTION_EVENT_ACTION_UP:
            audioEngine->setToneOn(false);
            break;
        default:
            break;
    }
}

JNIEXPORT void JNICALL
Java_com_goofy_goober_wavy_MainActivity_startEngine(JNIEnv *env, jobject /* this */) {
    audioEngine->start();
}

JNIEXPORT void JNICALL
Java_com_goofy_goober_wavy_MainActivity_stopEngine(JNIEnv *env, jobject /* this */) {
    audioEngine->stop();
}

}
