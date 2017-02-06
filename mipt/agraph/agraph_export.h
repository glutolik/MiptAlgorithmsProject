
#ifndef AGRAPH_EXPORT_H
#define AGRAPH_EXPORT_H

#ifdef AGRAPH_STATIC_DEFINE
#  define AGRAPH_EXPORT
#  define AGRAPH_NO_EXPORT
#else
#  ifndef AGRAPH_EXPORT
#    ifdef agraph_EXPORTS
        /* We are building this library */
#      define AGRAPH_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define AGRAPH_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef AGRAPH_NO_EXPORT
#    define AGRAPH_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef AGRAPH_DEPRECATED
#  define AGRAPH_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef AGRAPH_DEPRECATED_EXPORT
#  define AGRAPH_DEPRECATED_EXPORT AGRAPH_EXPORT AGRAPH_DEPRECATED
#endif

#ifndef AGRAPH_DEPRECATED_NO_EXPORT
#  define AGRAPH_DEPRECATED_NO_EXPORT AGRAPH_NO_EXPORT AGRAPH_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define AGRAPH_NO_DEPRECATED
#endif

#endif
