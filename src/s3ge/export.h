#ifndef S3GE_H_2021_2_18_619939EE26664E3B8696A9CFA5DA2053_
#define S3GE_H_2021_2_18_619939EE26664E3B8696A9CFA5DA2053_

#if defined(WIN32)
#if defined(BUILDING_S3GE)
#define S3GE_EXPORT __declspec(dllexport)
#else
#define S3GE_EXPORT __declspec(dllimport)
#endif
#else
#define S3GE_EXPORT
#endif

#endif // S3GE_H_2021_2_18_619939EE26664E3B8696A9CFA5DA2053_
