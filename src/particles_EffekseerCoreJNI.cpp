#ifndef SWIGJAVA
#define SWIGJAVA
#endif


#ifdef __cplusplus

/* SwigValueWrapper is described in swig.swg */
template<typename T>
class SwigValueWrapper {
    struct SwigMovePointer {
        T *ptr;

        SwigMovePointer(T *p) : ptr(p) {}

        ~SwigMovePointer() { delete ptr; }

        SwigMovePointer &operator=(SwigMovePointer &rhs) {
            T *oldptr = ptr;
            ptr = 0;
            delete oldptr;
            ptr = rhs.ptr;
            rhs.ptr = 0;
            return *this;
        }
    } pointer;

    SwigValueWrapper &operator=(const SwigValueWrapper<T> &rhs);

    SwigValueWrapper(const SwigValueWrapper<T> &rhs);

public:
    SwigValueWrapper() : pointer(0) {}

    SwigValueWrapper &operator=(const T &t) {
        SwigMovePointer tmp(new T(t));
        pointer = tmp;
        return *this;
    }

    operator T &() const { return *pointer.ptr; }

    T *operator&() { return pointer.ptr; }
};

template<typename T>
T SwigValueInit() {
    return T();
}

#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
    SWIG_JavaOutOfMemoryError = 1,
    SWIG_JavaIOException,
    SWIG_JavaRuntimeException,
    SWIG_JavaIndexOutOfBoundsException,
    SWIG_JavaArithmeticException,
    SWIG_JavaIllegalArgumentException,
    SWIG_JavaNullPointerException,
    SWIG_JavaDirectorPureVirtual,
    SWIG_JavaUnknownError,
    SWIG_JavaIllegalStateException,
} SWIG_JavaExceptionCodes;

typedef struct {
    SWIG_JavaExceptionCodes code;
    const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
    jclass excep;
    static const SWIG_JavaExceptions_t java_exceptions[] = {
            {SWIG_JavaOutOfMemoryError,          "java/lang/OutOfMemoryError"},
            {SWIG_JavaIOException,               "java/io/IOException"},
            {SWIG_JavaRuntimeException,          "java/lang/RuntimeException"},
            {SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException"},
            {SWIG_JavaArithmeticException,       "java/lang/ArithmeticException"},
            {SWIG_JavaIllegalArgumentException,  "java/lang/IllegalArgumentException"},
            {SWIG_JavaNullPointerException,      "java/lang/NullPointerException"},
            {SWIG_JavaDirectorPureVirtual,       "java/lang/RuntimeException"},
            {SWIG_JavaUnknownError,              "java/lang/UnknownError"},
            {SWIG_JavaIllegalStateException,     "java/lang/IllegalStateException"},
            {(SWIG_JavaExceptionCodes) 0,        "java/lang/UnknownError"}
    };
    const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

    while (except_ptr->code != code && except_ptr->code)
        except_ptr++;

    jenv->ExceptionClear();
    excep = jenv->FindClass(except_ptr->java_exception);
    if (excep)
        jenv->ThrowNew(excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include "lib/EffekseerBackendCore.h"
#include "lib/EffekseerEffectCore.h"
#include "lib/EffekseerManagerCore.h"
#include "lib/Vector4Map.h"


#include <stdint.h>        // Use the C99 official header
#include <iostream>


int char16_len(const char16_t *s) {
    int cnt = 0;
    while (*s++) cnt++;
    return cnt;
}

/*

public class com.example.jni.JNIJavaCallback {
  static {};
    descriptor: ()V

  public com.example.jni.JNIJavaCallback();
    descriptor: ()V

  public static void main(java.lang.String[]);
    descriptor: ([Ljava/lang/String;)V

  public native void callback();
    descriptor: ()V

  public static void printNum(int);
    descriptor: (I)V  // <---- Needed

  public void printFloat(float);
    descriptor: (F)V  // <---- Needed
}


*/





#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jlong JNICALL
Java_particles_EffekseerCoreJNI_new_1EffekseerBackendCore
        (JNIEnv *env, jclass jc) {


    jlong res = 0;
    (void) jc;
    EffekseerBackendCore *result = 0;

    result = (EffekseerBackendCore *) new EffekseerBackendCore();
    *(EffekseerBackendCore **) &res = result;

//  jmethodID mt = env->GetMethodID(jc,"debugLib","([Ljava/lang/String;)V");
//   env->CallStaticVoidMethod(jc,mt,"new_1EffekseerBackendCore" );


    return res;
}


SWIGEXPORT void JNICALL
Java_particles_EffekseerCoreJNI_delete_1EffekseerBackendCore
        (JNIEnv
         *env,
         jclass cl, jlong
         longg) {

    EffekseerBackendCore *arg1 = (EffekseerBackendCore *)
            0;

    (void)
            env;
    (void)
            cl;
    arg1 = *(EffekseerBackendCore **) &longg;
    delete
            arg1;

//  jmethodID mt = env->GetMethodID(cl,"debugLib","([Ljava/lang/String;)V");
//   env->CallStaticVoidMethod(cl,mt,"delete_1EffekseerBackendCore" );

}


SWIGEXPORT jint JNICALL
Java_particles_EffekseerCoreJNI_EffekseerBackendCore_1GetDevice(JNIEnv
                                                                *jenv,
                                                                jclass jcls
) {
    jint jresult = 0;
    EffekseerCoreDeviceType result;

    (void)
            jenv;
    (void)
            jcls;
    result = (EffekseerCoreDeviceType) EffekseerBackendCore::GetDevice();
    jresult = (jint) result;
    return
            jresult;
}


SWIGEXPORT jboolean JNICALL
Java_particles_EffekseerCoreJNI_EffekseerBackendCore_1InitializeAsOpenGL
        (JNIEnv
         *env,
         jclass cl
        ) {

    jboolean jresult = 0;
    bool result;

    (void)
            env;
    (void)
            cl;
    result = (bool) EffekseerBackendCore::InitializeAsOpenGL();
    jresult = (jboolean) result;
    return
            jresult;
}

SWIGEXPORT void JNICALL
Java_particles_EffekseerCoreJNI_EffekseerBackendCore_1Terminate
        (JNIEnv
         *env,
         jclass cl
        ) {

    (void)
            env;
    (void)
            cl;

    EffekseerBackendCore::Terminate();


}

SWIGEXPORT jlong JNICALL
Java_particles_EffekseerCoreJNI_new_1EffekseerEffectCore
        (JNIEnv
         *env,
         jclass cl
        ) {

    jlong jresult = 0;
    EffekseerEffectCore *result = 0;

    (void)
            env;
    (void)
            cl;
    result = (EffekseerEffectCore *) new EffekseerEffectCore();
    *(EffekseerEffectCore **) &
            jresult = result;
    return
            jresult;

}


SWIGEXPORT void JNICALL
Java_particles_EffekseerCoreJNI_delete_1EffekseerEffectCore
        (JNIEnv
         *env,
         jclass cl, jlong
         lon) {


    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;

    (void)
            env;
    (void)
            cl;
    arg1 = *(EffekseerEffectCore **) &lon;
    delete
            arg1;

}


SWIGEXPORT jboolean JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1Load
        (JNIEnv
         *env,
         jclass cl, jlong
         lon,
         jobject obj, jbyteArray
         arrayb,
         jint int1, jfloat
         floa,
         jlong id, jstring
         path) {

    jboolean jresult = 0;
    EffekseerManagerCore *core = (EffekseerManagerCore *) 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    char *arg2 = (char *) 0;
    int arg3;
    float arg4;
    bool result;

    (void)
            env;
    (void)
            cl;
    (void)
            obj;
    arg1 = *(EffekseerEffectCore **) &lon;
    core = *(EffekseerManagerCore **) &id;

    {
        arg2 = (char *) env->GetByteArrayElements(arrayb, 0);
    }
    arg3 = (int) int1;
    arg4 = (float) floa;


    result = (bool) (arg1)->Load(core->manager_, (const unsigned char *) arg2, arg3, arg4);


    jresult = (jboolean) result;
    {
        env->
                ReleaseByteArrayElements(arrayb, (jbyte
        *) arg2, 0);
    }

    return
            jresult;
}


SWIGEXPORT jstring JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1GetTexturePath
        (JNIEnv
         *env,
         jclass cl, jlong
         lon,
         jobject obj, jint
         int1,
         jint int2
        ) {

    jstring jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    int32_t arg2;
    EffekseerTextureType arg3;
    char16_t *result = 0;

    (void)
            env;
    (void)
            cl;
    (void)
            obj;
    arg1 = *(EffekseerEffectCore **) &lon;
    arg2 = (int32_t) int1;
    arg3 = (EffekseerTextureType) int2;
    result = (char16_t *) ((EffekseerEffectCore const *) arg1)->GetTexturePath(arg2, arg3);
    {
        if (result)
            jresult = env->NewString((const jchar *) result, char16_len(result));
    }
    return
            jresult;


}




/*
 * Class:     particles_EffekseerCoreJNI
 * Method:    SetCameraRotate
 * Signature: (JLparticles/EffekseerManagerCore;FFF)V
 */
SWIGEXPORT void JNICALL Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1SetCameraRotate
        (JNIEnv *env, jclass cls, jlong ptr, jobject jobject1, jint jarg2, jfloat x, jfloat y, jfloat z) {


    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;
    int arg2;
    float arg3;
    float arg4;
    float arg5;

    (void) env;
    (void) cls;
    (void) jobject1;
    arg1 = *(EffekseerManagerCore **) &ptr;
    arg2 = (int) jarg2;
    arg3 = (float) x;
    arg4 = (float) y;
    arg5 = (float) z;


    (arg1)->SetCameraRotate(arg3, arg4, arg5);


}


SWIGEXPORT void JNICALL Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1SetProjectionMatrix
        (JNIEnv *env, jclass cls, jlong ptr, jobject jobject1, jfloatArray projection,jfloatArray camera) {


    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;

    (void) env;
    (void) cls;
    (void) jobject1;
    arg1 = *(EffekseerManagerCore **) &ptr;

    jfloat *progec = env->GetFloatArrayElements(projection, 0);
    jfloat *came = env->GetFloatArrayElements(camera, 0);

    Vector4Map map;

    (arg1)->SetProjectionMatrix(map.map(progec),map.map(came));

    {
        env->ReleaseFloatArrayElements(projection, (jfloat *) progec, 0);
        env->ReleaseFloatArrayElements(projection, (jfloat *)came, 0);
    }





}

SWIGEXPORT jint
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1GetTextureCount(JNIEnv
                                                                     *jenv,
                                                                     jclass jcls, jlong
                                                                     jarg1,
                                                                     jobject jarg1_, jint
                                                                     jarg2) {
    jint jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    EffekseerTextureType arg2;
    int32_t result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    arg2 = (EffekseerTextureType) jarg2;
    result = (int32_t) ((EffekseerEffectCore const *) arg1)->GetTextureCount(arg2);
    jresult = (jint)
            result;
    return
            jresult;
}

SWIGEXPORT jboolean
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1LoadTexture(JNIEnv
                                                                 *jenv,
                                                                 jclass jcls, jlong
                                                                 jarg1,
                                                                 jobject jarg1_, jbyteArray
                                                                 jarg2,
                                                                 jint jarg3,
                                                                 jint
                                                                 jarg4,
                                                                 jint jarg5
) {
    jboolean jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    char *arg2 = (char *) 0;
    int arg3;
    int32_t arg4;
    EffekseerTextureType arg5;
    bool result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    {
        arg2 = (char *) jenv->GetByteArrayElements(jarg2, 0);
    }
    arg3 = (int) jarg3;
    arg4 = (int32_t) jarg4;
    arg5 = (EffekseerTextureType) jarg5;
    result = (bool) (arg1)->LoadTexture((const unsigned char *) arg2, arg3, arg4, arg5);
    jresult = (jboolean) result;
    {
        jenv->
                ReleaseByteArrayElements(jarg2, (jbyte
        *) arg2, 0);
    }

    return
            jresult;
}


SWIGEXPORT jboolean
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1HasTextureLoaded(JNIEnv
                                                                      *jenv,
                                                                      jclass jcls, jlong
                                                                      jarg1,
                                                                      jobject jarg1_, jint
                                                                      jarg2,
                                                                      jint jarg3
) {
    jboolean jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    int32_t arg2;
    EffekseerTextureType arg3;
    bool result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    arg2 = (int32_t) jarg2;
    arg3 = (EffekseerTextureType) jarg3;
    result = (bool) (arg1)->HasTextureLoaded(arg2, arg3);
    jresult = (jboolean) result;
    return
            jresult;
}


SWIGEXPORT jstring
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1GetModelPath(JNIEnv
                                                                  *jenv,
                                                                  jclass jcls, jlong
                                                                  jarg1,
                                                                  jobject jarg1_, jint
                                                                  jarg2) {
    jstring jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    int32_t arg2;
    char16_t *result = 0;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    arg2 = (int32_t) jarg2;
    result = (char16_t *) ((EffekseerEffectCore const *) arg1)->GetModelPath(arg2);
    {
        if (result)
            jresult = jenv->NewString((const jchar *) result, char16_len(result));
    }
    return
            jresult;
}

SWIGEXPORT jint
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1GetModelCount(JNIEnv
                                                                   *jenv,
                                                                   jclass jcls, jlong
                                                                   jarg1,
                                                                   jobject jarg1_
) {
    jint jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    int32_t result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    result = (int32_t) ((EffekseerEffectCore const *) arg1)->GetModelCount();
    jresult = (jint)
            result;
    return
            jresult;
}


SWIGEXPORT jboolean
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1LoadModel(JNIEnv
                                                               *jenv,
                                                               jclass jcls, jlong
                                                               jarg1,
                                                               jobject jarg1_, jbyteArray
                                                               jarg2,
                                                               jint jarg3,
                                                               jint
                                                               jarg4) {
    jboolean jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    char *arg2 = (char *) 0;
    int arg3;
    int32_t arg4;
    bool result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    {
        arg2 = (char *) jenv->GetByteArrayElements(jarg2, 0);
    }
    arg3 = (int) jarg3;
    arg4 = (int32_t) jarg4;
    result = (bool) (arg1)->LoadModel((const unsigned char *) arg2, arg3, arg4);
    jresult = (jboolean) result;
    {
        jenv->ReleaseByteArrayElements(jarg2, (jbyte *) arg2, 0);
    }

    return
            jresult;
}


SWIGEXPORT jint
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1GetMaterialCount(JNIEnv
                                                                      *jenv,
                                                                      jclass jcls, jlong
                                                                      jarg1,
                                                                      jobject jarg1_
) {
    jint jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    int32_t result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    result = (int32_t) ((EffekseerEffectCore const *) arg1)->GetMaterialCount();
    jresult = (jint)
            result;
    return
            jresult;
}


SWIGEXPORT jboolean
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1LoadMaterial(JNIEnv
                                                                  *jenv,
                                                                  jclass jcls, jlong
                                                                  jarg1,
                                                                  jobject jarg1_, jbyteArray
                                                                  jarg2,
                                                                  jint jarg3,
                                                                  jint
                                                                  jarg4) {
    jboolean jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    char *arg2 = (char *) 0;
    int arg3;
    int32_t arg4;
    bool result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    {
        arg2 = (char *) jenv->GetByteArrayElements(jarg2, 0);
    }
    arg3 = (int) jarg3;
    arg4 = (int32_t) jarg4;
    result = (bool) (arg1)->LoadMaterial((const unsigned char *) arg2, arg3, arg4);
    jresult = (jboolean) result;
    {
        jenv->
                ReleaseByteArrayElements(jarg2, (jbyte
        *) arg2, 0);
    }

    return
            jresult;
}

SWIGEXPORT jstring JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1GetMaterialPath(JNIEnv
                                                                     *jenv,
                                                                     jclass jcls, jlong
                                                                     jarg1,
                                                                     jobject jarg1_, jint
                                                                     jarg2) {
    jstring jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    int32_t arg2;
    char16_t *result = 0;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    arg2 = (int32_t) jarg2;
    result = (char16_t *) ((EffekseerEffectCore const *) arg1)->GetMaterialPath(arg2);
    {
        if (result)
            jresult = jenv->NewString((const jchar *) result, char16_len(result));
    }
    return
            jresult;
}


SWIGEXPORT jboolean
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerEffectCore_1HasMaterialLoaded(JNIEnv
                                                                       *jenv,
                                                                       jclass jcls, jlong
                                                                       jarg1,
                                                                       jobject jarg1_, jint
                                                                       jarg2) {
    jboolean jresult = 0;
    EffekseerEffectCore *arg1 = (EffekseerEffectCore *) 0;
    int32_t arg2;
    bool result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerEffectCore **) &jarg1;
    arg2 = (int32_t) jarg2;
    result = (bool) (arg1)->HasMaterialLoaded(arg2);
    jresult = (jboolean) result;
    return
            jresult;
}


SWIGEXPORT jlong JNICALL
Java_particles_EffekseerCoreJNI_new_1EffekseerManagerCore(JNIEnv
                                                          *jenv,
                                                          jclass jcls
) {
    jlong jresult = 0;
    EffekseerManagerCore *result = 0;

    (void)
            jenv;
    (void)
            jcls;
    result = (EffekseerManagerCore *) new EffekseerManagerCore();
    *(EffekseerManagerCore **) &
            jresult = result;
    return
            jresult;
}


SWIGEXPORT void
JNICALL
Java_particles_EffekseerCoreJNI_delete_1EffekseerManagerCore(JNIEnv
                                                             *jenv,
                                                             jclass jcls, jlong
                                                             jarg1) {
    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;

    (void)
            jenv;
    (void)
            jcls;
    arg1 = *(EffekseerManagerCore **) &jarg1;
    delete
            arg1;
}


SWIGEXPORT jboolean
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1Initialize(JNIEnv
                                                                 *jenv,
                                                                 jclass jcls, jlong
                                                                 jarg1,
                                                                 jobject jarg1_, jint
                                                                 jarg2,
                                                                 jint id
) {
    jboolean jresult = 0;
    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;
    int32_t arg2;
    bool result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerManagerCore **) &jarg1;
    arg2 = (int32_t) jarg2;
    result = (bool) (arg1)->Initialize(arg2, (int32_t) id);
    jresult = (jboolean) result;
    return
            jresult;
}


SWIGEXPORT void
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1Update(JNIEnv
                                                             *jenv,
                                                             jclass jcls, jlong
                                                             jarg1,
                                                             jobject jarg1_, jfloat
                                                             jarg2) {
    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;
    float arg2;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerManagerCore **) &jarg1;
    arg2 = (float) jarg2;


    (arg1)->
            Update(arg2);
}


SWIGEXPORT jint
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1Play(JNIEnv
                                                           *jenv,
                                                           jclass jcls, jlong
                                                           jarg1,
                                                           jobject jarg1_, jlong
                                                           jarg2,
                                                           jobject jarg2_
) {
    jint jresult = 0;
    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;
    EffekseerEffectCore *arg2 = (EffekseerEffectCore *) 0;
    int result;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    (void)
            jarg2_;
    arg1 = *(EffekseerManagerCore **) &jarg1;
    arg2 = *(EffekseerEffectCore **) &jarg2;
    result = (int) (arg1)->Play(arg2);
    jresult = (jint)
            result;
    return
            jresult;
}


SWIGEXPORT void JNICALL Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1SetCameraPosition
        (JNIEnv *env, jclass cls, jlong ptr, jobject jobject1, jfloat x, jfloat y, jfloat z) {


    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;


    float arg3;
    float arg4;
    float arg5;

    (void) env;
    (void) cls;
    (void) jobject1;

    arg1 = *(EffekseerManagerCore **) &ptr;

    arg3 = (float) x;
    arg4 = (float) y;
    arg5 = (float) z;


    (arg1)->SetCameraPosition(arg3, arg4, arg5);


}

SWIGEXPORT void
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1SetEffectPosition
        (JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jfloat jarg3, jfloat jarg4, jfloat jarg5
        ) {
    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;
    int arg2;
    float arg3;
    float arg4;
    float arg5;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerManagerCore **) &jarg1;
    arg2 = (int) jarg2;
    arg3 = (float) jarg3;
    arg4 = (float) jarg4;
    arg5 = (float) jarg5;



    (arg1)->
            SetEffectPosition(arg2, arg3, arg4, arg5
    );
}


SWIGEXPORT void
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1DrawBack(JNIEnv
                                                               *jenv,
                                                               jclass jcls, jlong
                                                               jarg1,
                                                               jobject jarg1_
) {
    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerManagerCore **) &jarg1;
    (arg1)->

            DrawBack();

}


SWIGEXPORT void
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1DrawFront(JNIEnv
                                                                *jenv,
                                                                jclass jcls, jlong
                                                                jarg1,
                                                                jobject jarg1_
) {
    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;

    (void)
            jenv;
    (void)
            jcls;
    (void)
            jarg1_;
    arg1 = *(EffekseerManagerCore **) &jarg1;
    (arg1)->

            DrawFront();

}


SWIGEXPORT void
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1SetViewProjectionMatrixWithSimpleWindowOrthogonal
        (JNIEnv
         *env,
         jclass cl, jlong
         lon,
         jobject obj, jint
         int1,
         jint int2
        ) {

    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;
    int32_t arg2;
    int32_t arg3;

    (void)
            env;
    (void)
            cl;
    (void)
            obj;
    arg1 = *(EffekseerManagerCore **) &lon;
    arg2 = (int32_t) int1;
    arg3 = (int32_t) int2;
    (arg1)->
            SetViewProjectionMatrixWithSimpleWindowOrthogonal(arg2, arg3
    );

}

SWIGEXPORT void
JNICALL
Java_particles_EffekseerCoreJNI_EffekseerManagerCore_1SetViewProjectionMatrixWithSimpleWindowPerspective
        (JNIEnv *env, jclass cl, jlong lon, jobject obj, jfloat f1, jfloat f2, jfloatArray up, jfloat nearr,
         jfloat faea) {

    EffekseerManagerCore *arg1 = (EffekseerManagerCore *) 0;
    float_t arg2;
    float_t arg3;

    (void) env;
    (void) cl;
    (void) obj;
    arg1 = *(EffekseerManagerCore **) &lon;
    arg2 = (float_t) f1;
    arg3 = (float_t) f2;

    float_t nr = (float_t) nearr;
    float_t fr = (float_t) faea;


    jfloat *upp = env->GetFloatArrayElements(up, 0);


    (arg1)->SetViewProjectionMatrixWithSimpleWindowPerspective(arg2, arg3, upp, nr, fr);

    {
        env->ReleaseFloatArrayElements(up, (jfloat *) upp, 0);
    }

}


#ifdef __cplusplus
}
#endif
