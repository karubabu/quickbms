// by Luigi Auriemma
// created for compatibility with old Windows systems and old Mingw 32, and for adding support of additional API

/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include "winapifamily.h"

#ifndef __BCRYPT_H__
#define __BCRYPT_H__

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#if !defined (_NTDEF_) && !defined (_NTSTATUS_PSDK)
#define _NTSTATUS_PSDK
  typedef LONG NTSTATUS,*PNTSTATUS;
#endif

#ifndef BCRYPT_SUCCESS
#define BCRYPT_SUCCESS(Status) (((NTSTATUS) (Status)) >= 0)
#endif

#ifndef CONST
#define CONST const
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#define BCRYPT_OBJECT_ALIGNMENT 16

#define BCRYPT_STRUCT_ALIGNMENT

#define BCRYPT_KDF_HASH L"HASH"
#define BCRYPT_KDF_HMAC L"HMAC"
#define BCRYPT_KDF_TLS_PRF L"TLS_PRF"
#define BCRYPT_KDF_SP80056A_CONCAT L"SP800_56A_CONCAT"

#define KDF_HASH_ALGORITHM 0x0
#define KDF_SECRET_PREPEND 0x1
#define KDF_SECRET_APPEND 0x2
#define KDF_HMAC_KEY 0x3
#define KDF_TLS_PRF_LABEL 0x4
#define KDF_TLS_PRF_SEED 0x5
#define KDF_SECRET_HANDLE 0x6
#define KDF_TLS_PRF_PROTOCOL 0x7
#define KDF_ALGORITHMID 0x8
#define KDF_PARTYUINFO 0x9
#define KDF_PARTYVINFO 0xa
#define KDF_SUPPPUBINFO 0xb
#define KDF_SUPPPRIVINFO 0xc
#define KDF_LABEL 0xd
#define KDF_CONTEXT 0xe
#define KDF_SALT 0xf
#define KDF_ITERATION_COUNT 0x10
#define KDF_GENERIC_PARAMETER 0x11
#define KDF_KEYBITLENGTH 0x12

#define KDF_USE_SECRET_AS_HMAC_KEY_FLAG 1

#define BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION 1

#define BCRYPT_AUTH_MODE_CHAIN_CALLS_FLAG 0x00000001
#define BCRYPT_AUTH_MODE_IN_PROGRESS_FLAG 0x00000002

#define BCRYPT_INIT_AUTH_MODE_INFO(_AUTH_INFO_STRUCT_) \
  RtlZeroMemory ((&_AUTH_INFO_STRUCT_), sizeof (BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO)); \
  (_AUTH_INFO_STRUCT_).cbSize = sizeof (BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO); \
  (_AUTH_INFO_STRUCT_).dwInfoVersion = BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION;

#define BCRYPT_OPAQUE_KEY_BLOB L"OpaqueKeyBlob"
#define BCRYPT_KEY_DATA_BLOB L"KeyDataBlob"
#define BCRYPT_AES_WRAP_KEY_BLOB L"Rfc3565KeyWrapBlob"

#define BCRYPT_ALGORITHM_NAME L"AlgorithmName"
#define BCRYPT_AUTH_TAG_LENGTH L"AuthTagLength"
#define BCRYPT_BLOCK_LENGTH L"BlockLength"
#define BCRYPT_BLOCK_SIZE_LIST L"BlockSizeList"
#define BCRYPT_CHAINING_MODE L"ChainingMode"
#define BCRYPT_CHAIN_MODE_CBC L"ChainingModeCBC"
#define BCRYPT_CHAIN_MODE_CCM L"ChainingModeCCM"
#define BCRYPT_CHAIN_MODE_CFB L"ChainingModeCFB"
#define BCRYPT_CHAIN_MODE_ECB L"ChainingModeECB"
#define BCRYPT_CHAIN_MODE_GCM L"ChainingModeGCM"
#define BCRYPT_CHAIN_MODE_NA L"ChainingModeN/A"
#define BCRYPT_EFFECTIVE_KEY_LENGTH L"EffectiveKeyLength"
#define BCRYPT_HASH_BLOCK_LENGTH L"HashBlockLength"
#define BCRYPT_HASH_LENGTH L"HashDigestLength"
#define BCRYPT_HASH_OID_LIST L"HashOIDList"
#define BCRYPT_INITIALIZATION_VECTOR L"IV"
#define BCRYPT_IS_KEYED_HASH L"IsKeyedHash"
#define BCRYPT_IS_REUSABLE_HASH L"IsReusableHash"
#define BCRYPT_KEY_LENGTH L"KeyLength"
#define BCRYPT_KEY_LENGTHS L"KeyLengths"
#define BCRYPT_KEY_OBJECT_LENGTH L"KeyObjectLength"
#define BCRYPT_KEY_STRENGTH L"KeyStrength"
#define BCRYPT_MESSAGE_BLOCK_LENGTH L"MessageBlockLength"
#define BCRYPT_OBJECT_LENGTH L"ObjectLength"
#define BCRYPT_PADDING_SCHEMES L"PaddingSchemes"
#define BCRYPT_PCP_PLATFORM_TYPE_PROPERTY L"PCP_PLATFORM_TYPE"
#define BCRYPT_PCP_PROVIDER_VERSION_PROPERTY L"PCP_PROVIDER_VERSION"
#define BCRYPT_PRIMITIVE_TYPE L"PrimitiveType"
#define BCRYPT_PROVIDER_HANDLE L"ProviderHandle"
#define BCRYPT_SIGNATURE_LENGTH L"SignatureLength"

#define BCRYPT_SUPPORTED_PAD_ROUTER 0x00000001
#define BCRYPT_SUPPORTED_PAD_PKCS1_ENC 0x00000002
#define BCRYPT_SUPPORTED_PAD_PKCS1_SIG 0x00000004
#define BCRYPT_SUPPORTED_PAD_OAEP 0x00000008
#define BCRYPT_SUPPORTED_PAD_PSS 0x00000010

#define BCRYPT_PROV_DISPATCH 0x00000001

#define BCRYPT_BLOCK_PADDING 0x00000001

#define BCRYPT_PAD_NONE 0x00000001
#define BCRYPT_PAD_PKCS1 0x00000002
#define BCRYPT_PAD_OAEP 0x00000004
#define BCRYPT_PAD_PSS 0x00000008

#define BCRYPTBUFFER_VERSION 0

  typedef struct __BCRYPT_KEY_LENGTHS_STRUCT {
    ULONG dwMinLength;
    ULONG dwMaxLength;
    ULONG dwIncrement;
  } BCRYPT_KEY_LENGTHS_STRUCT;

  typedef BCRYPT_KEY_LENGTHS_STRUCT BCRYPT_AUTH_TAG_LENGTHS_STRUCT;

  typedef struct _BCRYPT_OID {
    ULONG cbOID;
    PUCHAR pbOID;
  } BCRYPT_OID;

  typedef struct _BCRYPT_OID_LIST {
    ULONG dwOIDCount;
    BCRYPT_OID *pOIDs;
  } BCRYPT_OID_LIST;

  typedef struct _BCRYPT_PKCS1_PADDING_INFO {
    LPCWSTR pszAlgId;
  } BCRYPT_PKCS1_PADDING_INFO;

  typedef struct _BCRYPT_PSS_PADDING_INFO {
    LPCWSTR pszAlgId;
    ULONG cbSalt;
  } BCRYPT_PSS_PADDING_INFO;

  typedef struct _BCRYPT_OAEP_PADDING_INFO {
    LPCWSTR pszAlgId;
    PUCHAR pbLabel;
    ULONG cbLabel;
  } BCRYPT_OAEP_PADDING_INFO;

  typedef struct _BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO {
    ULONG cbSize;
    ULONG dwInfoVersion;
    PUCHAR pbNonce;
    ULONG cbNonce;
    PUCHAR pbAuthData;
    ULONG cbAuthData;
    PUCHAR pbTag;
    ULONG cbTag;
    PUCHAR pbMacContext;
    ULONG cbMacContext;
    ULONG cbAAD;
    ULONGLONG cbData;
    ULONG dwFlags;
  } BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO,*PBCRYPT_AUTHENTICATED_CIPHER_MODE_INFO;
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
  typedef struct _BCryptBuffer {
    ULONG cbBuffer;
    ULONG BufferType;
    PVOID pvBuffer;
  } BCryptBuffer,*PBCryptBuffer;

  typedef struct _BCryptBufferDesc {
    ULONG ulVersion;
    ULONG cBuffers;
    PBCryptBuffer pBuffers;
  } BCryptBufferDesc,*PBCryptBufferDesc;
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)

#define BCRYPT_PUBLIC_KEY_BLOB L"PUBLICBLOB"
#define BCRYPT_PRIVATE_KEY_BLOB L"PRIVATEBLOB"

#define BCRYPT_RSAPUBLIC_BLOB L"RSAPUBLICBLOB"
#define BCRYPT_RSAPRIVATE_BLOB L"RSAPRIVATEBLOB"
#define LEGACY_RSAPUBLIC_BLOB L"CAPIPUBLICBLOB"
#define LEGACY_RSAPRIVATE_BLOB L"CAPIPRIVATEBLOB"

#define BCRYPT_RSAPUBLIC_MAGIC 0x31415352
#define BCRYPT_RSAPRIVATE_MAGIC 0x32415352

#define BCRYPT_RSAFULLPRIVATE_BLOB L"RSAFULLPRIVATEBLOB"

#define BCRYPT_RSAFULLPRIVATE_MAGIC 0x33415352

#define BCRYPT_GLOBAL_PARAMETERS L"SecretAgreementParam"
#define BCRYPT_PRIVATE_KEY L"PrivKeyVal"

#define BCRYPT_ECCPUBLIC_BLOB L"ECCPUBLICBLOB"
#define BCRYPT_ECCPRIVATE_BLOB L"ECCPRIVATEBLOB"

#define BCRYPT_ECDH_PUBLIC_P256_MAGIC 0x314b4345
#define BCRYPT_ECDH_PRIVATE_P256_MAGIC 0x324b4345
#define BCRYPT_ECDH_PUBLIC_P384_MAGIC 0x334b4345
#define BCRYPT_ECDH_PRIVATE_P384_MAGIC 0x344b4345
#define BCRYPT_ECDH_PUBLIC_P521_MAGIC 0x354b4345
#define BCRYPT_ECDH_PRIVATE_P521_MAGIC 0x364b4345

#define BCRYPT_ECDSA_PUBLIC_P256_MAGIC 0x31534345
#define BCRYPT_ECDSA_PRIVATE_P256_MAGIC 0x32534345
#define BCRYPT_ECDSA_PUBLIC_P384_MAGIC 0x33534345
#define BCRYPT_ECDSA_PRIVATE_P384_MAGIC 0x34534345
#define BCRYPT_ECDSA_PUBLIC_P521_MAGIC 0x35534345
#define BCRYPT_ECDSA_PRIVATE_P521_MAGIC 0x36534345

#define BCRYPT_DH_PUBLIC_BLOB L"DHPUBLICBLOB"
#define BCRYPT_DH_PRIVATE_BLOB L"DHPRIVATEBLOB"
#define LEGACY_DH_PUBLIC_BLOB L"CAPIDHPUBLICBLOB"
#define LEGACY_DH_PRIVATE_BLOB L"CAPIDHPRIVATEBLOB"

#define BCRYPT_DH_PUBLIC_MAGIC 0x42504844
#define BCRYPT_DH_PRIVATE_MAGIC 0x56504844

#define BCRYPT_DH_PARAMETERS L"DHParameters"
#define BCRYPT_DH_PARAMETERS_MAGIC 0x4d504844

#define BCRYPT_DSA_PUBLIC_BLOB L"DSAPUBLICBLOB"
#define BCRYPT_DSA_PRIVATE_BLOB L"DSAPRIVATEBLOB"
#define LEGACY_DSA_PUBLIC_BLOB L"CAPIDSAPUBLICBLOB"
#define LEGACY_DSA_PRIVATE_BLOB L"CAPIDSAPRIVATEBLOB"
#define LEGACY_DSA_V2_PUBLIC_BLOB L"V2CAPIDSAPUBLICBLOB"
#define LEGACY_DSA_V2_PRIVATE_BLOB L"V2CAPIDSAPRIVATEBLOB"

#define BCRYPT_DSA_PUBLIC_MAGIC 0x42505344
#define BCRYPT_DSA_PRIVATE_MAGIC 0x56505344
#define BCRYPT_DSA_PUBLIC_MAGIC_V2 0x32425044
#define BCRYPT_DSA_PRIVATE_MAGIC_V2 0x32565044

#define BCRYPT_KEY_DATA_BLOB_MAGIC 0x4d42444b
#define BCRYPT_KEY_DATA_BLOB_VERSION1 0x1

#define BCRYPT_DSA_PARAMETERS L"DSAParameters"
#define BCRYPT_DSA_PARAMETERS_MAGIC 0x4d505344
#define BCRYPT_DSA_PARAMETERS_MAGIC_V2 0x324d5044

#define MS_PRIMITIVE_PROVIDER L"Microsoft Primitive Provider"
#define MS_PLATFORM_CRYPTO_PROVIDER L"Microsoft Platform Crypto Provider"

#define BCRYPT_RSA_ALGORITHM L"RSA"
#define BCRYPT_RSA_SIGN_ALGORITHM L"RSA_SIGN"
#define BCRYPT_DH_ALGORITHM L"DH"
#define BCRYPT_DSA_ALGORITHM L"DSA"
#define BCRYPT_RC2_ALGORITHM L"RC2"
#define BCRYPT_RC4_ALGORITHM L"RC4"
#define BCRYPT_AES_ALGORITHM L"AES"
#define BCRYPT_DES_ALGORITHM L"DES"
#define BCRYPT_DESX_ALGORITHM L"DESX"
#define BCRYPT_3DES_ALGORITHM L"3DES"
#define BCRYPT_3DES_112_ALGORITHM L"3DES_112"
#define BCRYPT_MD2_ALGORITHM L"MD2"
#define BCRYPT_MD4_ALGORITHM L"MD4"
#define BCRYPT_MD5_ALGORITHM L"MD5"
#define BCRYPT_SHA1_ALGORITHM L"SHA1"
#define BCRYPT_SHA256_ALGORITHM L"SHA256"
#define BCRYPT_SHA384_ALGORITHM L"SHA384"
#define BCRYPT_SHA512_ALGORITHM L"SHA512"
#define BCRYPT_AES_GMAC_ALGORITHM L"AES-GMAC"
#define BCRYPT_AES_CMAC_ALGORITHM L"AES-CMAC"
#define BCRYPT_ECDSA_P256_ALGORITHM L"ECDSA_P256"
#define BCRYPT_ECDSA_P384_ALGORITHM L"ECDSA_P384"
#define BCRYPT_ECDSA_P521_ALGORITHM L"ECDSA_P521"
#define BCRYPT_ECDH_P256_ALGORITHM L"ECDH_P256"
#define BCRYPT_ECDH_P384_ALGORITHM L"ECDH_P384"
#define BCRYPT_ECDH_P521_ALGORITHM L"ECDH_P521"
#define BCRYPT_RNG_ALGORITHM L"RNG"
#define BCRYPT_RNG_FIPS186_DSA_ALGORITHM L"FIPS186DSARNG"
#define BCRYPT_RNG_DUAL_EC_ALGORITHM L"DUALECRNG"
#define BCRYPT_SP800108_CTR_HMAC_ALGORITHM L"SP800_108_CTR_HMAC"
#define BCRYPT_SP80056A_CONCAT_ALGORITHM L"SP800_56A_CONCAT"
#define BCRYPT_PBKDF2_ALGORITHM L"PBKDF2"
#define BCRYPT_CAPI_KDF_ALGORITHM L"CAPI_KDF"

#define BCRYPT_CIPHER_INTERFACE 0x00000001
#define BCRYPT_HASH_INTERFACE 0x00000002
#define BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE 0x00000003
#define BCRYPT_SECRET_AGREEMENT_INTERFACE 0x00000004
#define BCRYPT_SIGNATURE_INTERFACE 0x00000005
#define BCRYPT_RNG_INTERFACE 0x00000006
#define BCRYPT_KEY_DERIVATION_INTERFACE 0x00000007

#define BCRYPT_ALG_HANDLE_HMAC_FLAG 0x00000008
#define BCRYPT_CAPI_AES_FLAG 0x00000010
#define BCRYPT_HASH_REUSABLE_FLAG 0x00000020

#define BCRYPT_BUFFERS_LOCKED_FLAG 0x00000040

#define BCRYPT_CIPHER_OPERATION 0x00000001
#define BCRYPT_HASH_OPERATION 0x00000002
#define BCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION 0x00000004
#define BCRYPT_SECRET_AGREEMENT_OPERATION 0x00000008
#define BCRYPT_SIGNATURE_OPERATION 0x00000010
#define BCRYPT_RNG_OPERATION 0x00000020
#define BCRYPT_KEY_DERIVATION_OPERATION 0x00000040

#define BCRYPT_PUBLIC_KEY_FLAG 0x00000001
#define BCRYPT_PRIVATE_KEY_FLAG 0x00000002

#define BCRYPT_NO_KEY_VALIDATION 0x00000008

#define BCRYPT_RNG_USE_ENTROPY_IN_BUFFER 0x00000001
#define BCRYPT_USE_SYSTEM_PREFERRED_RNG 0x00000002

#define BCRYPT_MAKE_INTERFACE_VERSION(major, minor) { (USHORT)major,(USHORT)minor}
#define BCRYPT_IS_INTERFACE_VERSION_COMPATIBLE(loader, provider) ((loader).MajorVersion <= (provider).MajorVersion)

#define BCRYPT_CIPHER_INTERFACE_VERSION_1 BCRYPT_MAKE_INTERFACE_VERSION (1, 0)
#define BCRYPT_HASH_INTERFACE_VERSION_1 BCRYPT_MAKE_INTERFACE_VERSION (1, 0)
#define BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE_VERSION_1 BCRYPT_MAKE_INTERFACE_VERSION (1, 0)
#define BCRYPT_SECRET_AGREEMENT_INTERFACE_VERSION_1 BCRYPT_MAKE_INTERFACE_VERSION (1, 0)
#define BCRYPT_SIGNATURE_INTERFACE_VERSION_1 BCRYPT_MAKE_INTERFACE_VERSION (1, 0)
#define BCRYPT_RNG_INTERFACE_VERSION_1 BCRYPT_MAKE_INTERFACE_VERSION (1, 0)

#define CRYPT_MIN_DEPENDENCIES (0x00000001)
#define CRYPT_PROCESS_ISOLATE (0x00010000)

#define CRYPT_UM (0x00000001)
#define CRYPT_KM (0x00000002)
#define CRYPT_MM (0x00000003)
#define CRYPT_ANY (0x00000004)

#define CRYPT_OVERWRITE (0x00000001)

#define CRYPT_LOCAL (0x00000001)
#define CRYPT_DOMAIN (0x00000002)

#define CRYPT_EXCLUSIVE (0x00000001)
#define CRYPT_OVERRIDE (0x00010000)

#define CRYPT_ALL_FUNCTIONS (0x00000001)
#define CRYPT_ALL_PROVIDERS (0x00000002)

#define CRYPT_PRIORITY_TOP (0x00000000)
#define CRYPT_PRIORITY_BOTTOM (0xffffffff)

#define CRYPT_DEFAULT_CONTEXT L"Default"

typedef PVOID BCRYPT_HANDLE;
  typedef PVOID BCRYPT_ALG_HANDLE;
  typedef PVOID BCRYPT_KEY_HANDLE;
  typedef PVOID BCRYPT_HASH_HANDLE;
  typedef PVOID BCRYPT_SECRET_HANDLE;

  typedef struct _BCRYPT_KEY_BLOB {
    ULONG Magic;
  } BCRYPT_KEY_BLOB;

  typedef struct _BCRYPT_RSAKEY_BLOB {
    ULONG Magic;
    ULONG BitLength;
    ULONG cbPublicExp;
    ULONG cbModulus;
    ULONG cbPrime1;
    ULONG cbPrime2;
  } BCRYPT_RSAKEY_BLOB;

  typedef struct _BCRYPT_ECCKEY_BLOB {
    ULONG dwMagic;
    ULONG cbKey;
  } BCRYPT_ECCKEY_BLOB,*PBCRYPT_ECCKEY_BLOB;

  typedef struct _BCRYPT_DH_KEY_BLOB {
    ULONG dwMagic;
    ULONG cbKey;
  } BCRYPT_DH_KEY_BLOB,*PBCRYPT_DH_KEY_BLOB;

  typedef struct _BCRYPT_DH_PARAMETER_HEADER {
    ULONG cbLength;
    ULONG dwMagic;
    ULONG cbKeyLength;
  } BCRYPT_DH_PARAMETER_HEADER;

  typedef struct _BCRYPT_DSA_KEY_BLOB {
    ULONG dwMagic;
    ULONG cbKey;
    UCHAR Count[4];
    UCHAR Seed[20];
    UCHAR q[20];
  } BCRYPT_DSA_KEY_BLOB,*PBCRYPT_DSA_KEY_BLOB;

  typedef enum {
    DSA_HASH_ALGORITHM_SHA1,
    DSA_HASH_ALGORITHM_SHA256,
    DSA_HASH_ALGORITHM_SHA512
  } HASHALGORITHM_ENUM;

  typedef enum {
    DSA_FIPS186_2,
    DSA_FIPS186_3
  } DSAFIPSVERSION_ENUM;
  typedef struct _BCRYPT_DSA_KEY_BLOB_V2 {
    ULONG dwMagic;
    ULONG cbKey;
    HASHALGORITHM_ENUM hashAlgorithm;
    DSAFIPSVERSION_ENUM standardVersion;
    ULONG cbSeedLength;
    ULONG cbGroupSize;
    UCHAR Count[4];
  } BCRYPT_DSA_KEY_BLOB_V2,*PBCRYPT_DSA_KEY_BLOB_V2;

  typedef struct _BCRYPT_KEY_DATA_BLOB_HEADER {
    ULONG dwMagic;
    ULONG dwVersion;
    ULONG cbKeyData;
  } BCRYPT_KEY_DATA_BLOB_HEADER,*PBCRYPT_KEY_DATA_BLOB_HEADER;

  typedef struct _BCRYPT_DSA_PARAMETER_HEADER {
    ULONG cbLength;
    ULONG dwMagic;
    ULONG cbKeyLength;
    UCHAR Count[4];
    UCHAR Seed[20];
    UCHAR q[20];
  } BCRYPT_DSA_PARAMETER_HEADER;

  typedef struct _BCRYPT_DSA_PARAMETER_HEADER_V2 {
    ULONG cbLength;
    ULONG dwMagic;
    ULONG cbKeyLength;
    HASHALGORITHM_ENUM hashAlgorithm;
    DSAFIPSVERSION_ENUM standardVersion;
    ULONG cbSeedLength;
    ULONG cbGroupSize;
    UCHAR Count[4];
  } BCRYPT_DSA_PARAMETER_HEADER_V2;

  typedef struct _BCRYPT_ALGORITHM_IDENTIFIER {
    LPWSTR pszName;
    ULONG dwClass;
    ULONG dwFlags;
  } BCRYPT_ALGORITHM_IDENTIFIER;

  typedef struct _BCRYPT_PROVIDER_NAME {
    LPWSTR pszProviderName;
  } BCRYPT_PROVIDER_NAME;

  typedef struct _BCRYPT_INTERFACE_VERSION {
    USHORT MajorVersion;
    USHORT MinorVersion;
  } BCRYPT_INTERFACE_VERSION,*PBCRYPT_INTERFACE_VERSION;

  typedef struct _CRYPT_INTERFACE_REG {
    ULONG dwInterface;
    ULONG dwFlags;
    ULONG cFunctions;
    PWSTR *rgpszFunctions;
  } CRYPT_INTERFACE_REG,*PCRYPT_INTERFACE_REG;

  typedef struct _CRYPT_IMAGE_REG {
    PWSTR pszImage;
    ULONG cInterfaces;
    PCRYPT_INTERFACE_REG *rgpInterfaces;
  } CRYPT_IMAGE_REG,*PCRYPT_IMAGE_REG;

  typedef struct _CRYPT_PROVIDER_REG {
    ULONG cAliases;
    PWSTR *rgpszAliases;
    PCRYPT_IMAGE_REG pUM;
    PCRYPT_IMAGE_REG pKM;
  } CRYPT_PROVIDER_REG,*PCRYPT_PROVIDER_REG;

  typedef struct _CRYPT_PROVIDERS {
    ULONG cProviders;
    PWSTR *rgpszProviders;
  } CRYPT_PROVIDERS,*PCRYPT_PROVIDERS;

  typedef struct _CRYPT_CONTEXT_CONFIG {
    ULONG dwFlags;
    ULONG dwReserved;
  } CRYPT_CONTEXT_CONFIG,*PCRYPT_CONTEXT_CONFIG;

  typedef struct _CRYPT_CONTEXT_FUNCTION_CONFIG {
    ULONG dwFlags;
    ULONG dwReserved;
  } CRYPT_CONTEXT_FUNCTION_CONFIG,*PCRYPT_CONTEXT_FUNCTION_CONFIG;

  typedef struct _CRYPT_CONTEXTS {
    ULONG cContexts;
    PWSTR *rgpszContexts;
  } CRYPT_CONTEXTS,*PCRYPT_CONTEXTS;

  typedef struct _CRYPT_CONTEXT_FUNCTIONS {
    ULONG cFunctions;
    PWSTR *rgpszFunctions;
  } CRYPT_CONTEXT_FUNCTIONS,*PCRYPT_CONTEXT_FUNCTIONS;

  typedef struct _CRYPT_CONTEXT_FUNCTION_PROVIDERS {
    ULONG cProviders;
    PWSTR *rgpszProviders;
  } CRYPT_CONTEXT_FUNCTION_PROVIDERS,*PCRYPT_CONTEXT_FUNCTION_PROVIDERS;

  typedef struct _CRYPT_PROPERTY_REF {
    PWSTR pszProperty;
    ULONG cbValue;
    PUCHAR pbValue;
  } CRYPT_PROPERTY_REF,*PCRYPT_PROPERTY_REF;

  typedef struct _CRYPT_IMAGE_REF {
    PWSTR pszImage;
    ULONG dwFlags;
  } CRYPT_IMAGE_REF,*PCRYPT_IMAGE_REF;

  typedef struct _CRYPT_PROVIDER_REF {
    ULONG dwInterface;
    PWSTR pszFunction;
    PWSTR pszProvider;
    ULONG cProperties;
    PCRYPT_PROPERTY_REF *rgpProperties;
    PCRYPT_IMAGE_REF pUM;
    PCRYPT_IMAGE_REF pKM;
  } CRYPT_PROVIDER_REF,*PCRYPT_PROVIDER_REF;

  typedef struct _CRYPT_PROVIDER_REFS {
    ULONG cProviders;
    PCRYPT_PROVIDER_REF *rgpProviders;
  } CRYPT_PROVIDER_REFS,*PCRYPT_PROVIDER_REFS;

  NTSTATUS WINAPI (*BCryptOpenAlgorithmProvider) (BCRYPT_ALG_HANDLE *phAlgorithm, LPCWSTR pszAlgId, LPCWSTR pszImplementation, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptEnumAlgorithms) (ULONG dwAlgOperations, ULONG *pAlgCount, BCRYPT_ALGORITHM_IDENTIFIER **ppAlgList, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptEnumProviders) (LPCWSTR pszAlgId, ULONG *pImplCount, BCRYPT_PROVIDER_NAME **ppImplList, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptGetProperty) (BCRYPT_HANDLE hObject, LPCWSTR pszProperty, PUCHAR pbOutput, ULONG cbOutput, ULONG *pcbResult, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptSetProperty) (BCRYPT_HANDLE hObject, LPCWSTR pszProperty, PUCHAR pbInput, ULONG cbInput, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptCloseAlgorithmProvider) (BCRYPT_ALG_HANDLE hAlgorithm, ULONG dwFlags) = NULL;
  VOID WINAPI (*BCryptFreeBuffer) (PVOID pvBuffer) = NULL;
  NTSTATUS WINAPI (*BCryptGenerateSymmetricKey) (BCRYPT_ALG_HANDLE hAlgorithm, BCRYPT_KEY_HANDLE *phKey, PUCHAR pbKeyObject, ULONG cbKeyObject, PUCHAR pbSecret, ULONG cbSecret, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptGenerateKeyPair) (BCRYPT_ALG_HANDLE hAlgorithm, BCRYPT_KEY_HANDLE *phKey, ULONG dwLength, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptEncrypt) (BCRYPT_KEY_HANDLE hKey, PUCHAR pbInput, ULONG cbInput, VOID *pPaddingInfo, PUCHAR pbIV, ULONG cbIV, PUCHAR pbOutput, ULONG cbOutput, ULONG *pcbResult, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptDecrypt) (BCRYPT_KEY_HANDLE hKey, PUCHAR pbInput, ULONG cbInput, VOID *pPaddingInfo, PUCHAR pbIV, ULONG cbIV, PUCHAR pbOutput, ULONG cbOutput, ULONG *pcbResult, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptExportKey) (BCRYPT_KEY_HANDLE hKey, BCRYPT_KEY_HANDLE hExportKey, LPCWSTR pszBlobType, PUCHAR pbOutput, ULONG cbOutput, ULONG *pcbResult, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptImportKey) (BCRYPT_ALG_HANDLE hAlgorithm, BCRYPT_KEY_HANDLE hImportKey, LPCWSTR pszBlobType, BCRYPT_KEY_HANDLE *phKey, PUCHAR pbKeyObject, ULONG cbKeyObject, PUCHAR pbInput, ULONG cbInput, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptImportKeyPair) (BCRYPT_ALG_HANDLE hAlgorithm, BCRYPT_KEY_HANDLE hImportKey, LPCWSTR pszBlobType, BCRYPT_KEY_HANDLE *phKey, PUCHAR pbInput, ULONG cbInput, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptDuplicateKey) (BCRYPT_KEY_HANDLE hKey, BCRYPT_KEY_HANDLE *phNewKey, PUCHAR pbKeyObject, ULONG cbKeyObject, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptFinalizeKeyPair) (BCRYPT_KEY_HANDLE hKey, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptDestroyKey) (BCRYPT_KEY_HANDLE hKey) = NULL;
  NTSTATUS WINAPI (*BCryptDestroySecret) (BCRYPT_SECRET_HANDLE hSecret) = NULL;
  NTSTATUS WINAPI (*BCryptSignHash) (BCRYPT_KEY_HANDLE hKey, VOID *pPaddingInfo, PUCHAR pbInput, ULONG cbInput, PUCHAR pbOutput, ULONG cbOutput, ULONG *pcbResult, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptVerifySignature) (BCRYPT_KEY_HANDLE hKey, VOID *pPaddingInfo, PUCHAR pbHash, ULONG cbHash, PUCHAR pbSignature, ULONG cbSignature, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptSecretAgreement) (BCRYPT_KEY_HANDLE hPrivKey, BCRYPT_KEY_HANDLE hPubKey, BCRYPT_SECRET_HANDLE *phAgreedSecret, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptDeriveKey) (BCRYPT_SECRET_HANDLE hSharedSecret, LPCWSTR pwszKDF, BCryptBufferDesc *pParameterList, PUCHAR pbDerivedKey, ULONG cbDerivedKey, ULONG *pcbResult, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptKeyDerivation) (BCRYPT_KEY_HANDLE hKey, BCryptBufferDesc *pParameterList, PUCHAR pbDerivedKey, ULONG cbDerivedKey, ULONG *pcbResult, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptCreateHash) (BCRYPT_ALG_HANDLE hAlgorithm, BCRYPT_HASH_HANDLE *phHash, PUCHAR pbHashObject, ULONG cbHashObject, PUCHAR pbSecret, ULONG cbSecret, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptHashData) (BCRYPT_HASH_HANDLE hHash, PUCHAR pbInput, ULONG cbInput, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptFinishHash) (BCRYPT_HASH_HANDLE hHash, PUCHAR pbOutput, ULONG cbOutput, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptDuplicateHash) (BCRYPT_HASH_HANDLE hHash, BCRYPT_HASH_HANDLE *phNewHash, PUCHAR pbHashObject, ULONG cbHashObject, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptDestroyHash) (BCRYPT_HASH_HANDLE hHash) = NULL;
  NTSTATUS WINAPI (*BCryptGenRandom) (BCRYPT_ALG_HANDLE hAlgorithm, PUCHAR pbBuffer, ULONG cbBuffer, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptDeriveKeyCapi) (BCRYPT_HASH_HANDLE hHash, BCRYPT_ALG_HANDLE hTargetAlg, PUCHAR pbDerivedKey, ULONG cbDerivedKey, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptDeriveKeyPBKDF2) (BCRYPT_ALG_HANDLE hPrf, PUCHAR pbPassword, ULONG cbPassword, PUCHAR pbSalt, ULONG cbSalt, ULONGLONG cIterations, PUCHAR pbDerivedKey, ULONG cbDerivedKey, ULONG dwFlags) = NULL;
  NTSTATUS WINAPI (*BCryptResolveProviders) (LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction, LPCWSTR pszProvider, ULONG dwMode, ULONG dwFlags, ULONG *pcbBuffer, PCRYPT_PROVIDER_REFS *ppBuffer) = NULL;
  NTSTATUS WINAPI (*BCryptGetFipsAlgorithmMode) (BOOLEAN *pfEnabled) = NULL;
  NTSTATUS WINAPI (*BCryptQueryProviderRegistration) (LPCWSTR pszProvider, ULONG dwMode, ULONG dwInterface, ULONG *pcbBuffer, PCRYPT_PROVIDER_REG *ppBuffer) = NULL;
  NTSTATUS WINAPI (*BCryptEnumRegisteredProviders) (ULONG *pcbBuffer, PCRYPT_PROVIDERS *ppBuffer) = NULL;
  NTSTATUS WINAPI (*BCryptCreateContext) (ULONG dwTable, LPCWSTR pszContext, PCRYPT_CONTEXT_CONFIG pConfig) = NULL;
  NTSTATUS WINAPI (*BCryptDeleteContext) (ULONG dwTable, LPCWSTR pszContext) = NULL;
  NTSTATUS WINAPI (*BCryptEnumContexts) (ULONG dwTable, ULONG *pcbBuffer, PCRYPT_CONTEXTS *ppBuffer) = NULL;
  NTSTATUS WINAPI (*BCryptConfigureContext) (ULONG dwTable, LPCWSTR pszContext, PCRYPT_CONTEXT_CONFIG pConfig) = NULL;
  NTSTATUS WINAPI (*BCryptQueryContextConfiguration) (ULONG dwTable, LPCWSTR pszContext, ULONG *pcbBuffer, PCRYPT_CONTEXT_CONFIG *ppBuffer) = NULL;
  NTSTATUS WINAPI (*BCryptAddContextFunction) (ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction, ULONG dwPosition) = NULL;
  NTSTATUS WINAPI (*BCryptRemoveContextFunction) (ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction) = NULL;
  NTSTATUS WINAPI (*BCryptEnumContextFunctions) (ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, ULONG *pcbBuffer, PCRYPT_CONTEXT_FUNCTIONS *ppBuffer) = NULL;
  NTSTATUS WINAPI (*BCryptConfigureContextFunction) (ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction, PCRYPT_CONTEXT_FUNCTION_CONFIG pConfig) = NULL;
  NTSTATUS WINAPI (*BCryptQueryContextFunctionConfiguration) (ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction, ULONG *pcbBuffer, PCRYPT_CONTEXT_FUNCTION_CONFIG *ppBuffer) = NULL;
  NTSTATUS WINAPI (*BCryptEnumContextFunctionProviders) (ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction, ULONG *pcbBuffer, PCRYPT_CONTEXT_FUNCTION_PROVIDERS *ppBuffer) = NULL;
  NTSTATUS WINAPI (*BCryptSetContextFunctionProperty) (ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction, LPCWSTR pszProperty, ULONG cbValue, PUCHAR pbValue) = NULL;
  NTSTATUS WINAPI (*BCryptQueryContextFunctionProperty) (ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction, LPCWSTR pszProperty, ULONG *pcbValue, PUCHAR *ppbValue) = NULL;
  NTSTATUS WINAPI (*BCryptRegisterConfigChangeNotify) (HANDLE *phEvent) = NULL;
  NTSTATUS WINAPI (*BCryptUnregisterConfigChangeNotify) (HANDLE hEvent) = NULL;

  NTSTATUS WINAPI (*BCryptAddContextFunctionProvider)(ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction, LPCWSTR pszProvider, ULONG dwPosition) = NULL;
  NTSTATUS WINAPI (*BCryptRegisterProvider)(LPCWSTR pszProvider, ULONG dwFlags, PCRYPT_PROVIDER_REG pReg) = NULL;
  NTSTATUS WINAPI (*BCryptRemoveContextFunctionProvider)(ULONG dwTable, LPCWSTR pszContext, ULONG dwInterface, LPCWSTR pszFunction, LPCWSTR pszProvider) = NULL;
  NTSTATUS WINAPI (*BCryptSetAuditingInterface)(void *) = NULL;
  NTSTATUS WINAPI (*BCryptUnregisterProvider)(LPCWSTR pszProvider) = NULL;

#endif

#ifdef __cplusplus
}
#endif



HMODULE BCrypt_init(void) {
    static HMODULE hLib = NULL;
    if(!hLib) {
        hLib = LoadLibrary("bcrypt.dll");
        if(hLib) {
            BCryptAddContextFunctionProvider = (void *)GetProcAddress(hLib, "BCryptAddContextFunctionProvider");
            BCryptCloseAlgorithmProvider = (void *)GetProcAddress(hLib, "BCryptCloseAlgorithmProvider");
            BCryptConfigureContext = (void *)GetProcAddress(hLib, "BCryptConfigureContext");
            BCryptConfigureContextFunction = (void *)GetProcAddress(hLib, "BCryptConfigureContextFunction");
            BCryptCreateContext = (void *)GetProcAddress(hLib, "BCryptCreateContext");
            BCryptCreateHash = (void *)GetProcAddress(hLib, "BCryptCreateHash");
            BCryptDecrypt = (void *)GetProcAddress(hLib, "BCryptDecrypt");
            BCryptDeleteContext = (void *)GetProcAddress(hLib, "BCryptDeleteContext");
            BCryptDeriveKey = (void *)GetProcAddress(hLib, "BCryptDeriveKey");
            BCryptDeriveKeyCapi = (void *)GetProcAddress(hLib, "BCryptDeriveKeyCapi");
            BCryptDeriveKeyPBKDF2 = (void *)GetProcAddress(hLib, "BCryptDeriveKeyPBKDF2");
            BCryptDestroyHash = (void *)GetProcAddress(hLib, "BCryptDestroyHash");
            BCryptDestroyKey = (void *)GetProcAddress(hLib, "BCryptDestroyKey");
            BCryptDestroySecret = (void *)GetProcAddress(hLib, "BCryptDestroySecret");
            BCryptDuplicateHash = (void *)GetProcAddress(hLib, "BCryptDuplicateHash");
            BCryptDuplicateKey = (void *)GetProcAddress(hLib, "BCryptDuplicateKey");
            BCryptEncrypt = (void *)GetProcAddress(hLib, "BCryptEncrypt");
            BCryptEnumAlgorithms = (void *)GetProcAddress(hLib, "BCryptEnumAlgorithms");
            BCryptEnumContextFunctionProviders = (void *)GetProcAddress(hLib, "BCryptEnumContextFunctionProviders");
            BCryptEnumContextFunctions = (void *)GetProcAddress(hLib, "BCryptEnumContextFunctions");
            BCryptEnumContexts = (void *)GetProcAddress(hLib, "BCryptEnumContexts");
            BCryptEnumProviders = (void *)GetProcAddress(hLib, "BCryptEnumProviders");
            BCryptEnumRegisteredProviders = (void *)GetProcAddress(hLib, "BCryptEnumRegisteredProviders");
            BCryptExportKey = (void *)GetProcAddress(hLib, "BCryptExportKey");
            BCryptFinalizeKeyPair = (void *)GetProcAddress(hLib, "BCryptFinalizeKeyPair");
            BCryptFinishHash = (void *)GetProcAddress(hLib, "BCryptFinishHash");
            BCryptFreeBuffer = (void *)GetProcAddress(hLib, "BCryptFreeBuffer");
            BCryptGenRandom = (void *)GetProcAddress(hLib, "BCryptGenRandom");
            BCryptGenerateKeyPair = (void *)GetProcAddress(hLib, "BCryptGenerateKeyPair");
            BCryptGenerateSymmetricKey = (void *)GetProcAddress(hLib, "BCryptGenerateSymmetricKey");
            BCryptGetFipsAlgorithmMode = (void *)GetProcAddress(hLib, "BCryptGetFipsAlgorithmMode");
            BCryptGetProperty = (void *)GetProcAddress(hLib, "BCryptGetProperty");
            BCryptHashData = (void *)GetProcAddress(hLib, "BCryptHashData");
            BCryptImportKey = (void *)GetProcAddress(hLib, "BCryptImportKey");
            BCryptImportKeyPair = (void *)GetProcAddress(hLib, "BCryptImportKeyPair");
            BCryptOpenAlgorithmProvider = (void *)GetProcAddress(hLib, "BCryptOpenAlgorithmProvider");
            BCryptQueryContextConfiguration = (void *)GetProcAddress(hLib, "BCryptQueryContextConfiguration");
            BCryptQueryContextFunctionConfiguration = (void *)GetProcAddress(hLib, "BCryptQueryContextFunctionConfiguration");
            BCryptQueryContextFunctionProperty = (void *)GetProcAddress(hLib, "BCryptQueryContextFunctionProperty");
            BCryptQueryProviderRegistration = (void *)GetProcAddress(hLib, "BCryptQueryProviderRegistration");
            BCryptRegisterConfigChangeNotify = (void *)GetProcAddress(hLib, "BCryptRegisterConfigChangeNotify");
            BCryptRegisterProvider = (void *)GetProcAddress(hLib, "BCryptRegisterProvider");
            BCryptRemoveContextFunction = (void *)GetProcAddress(hLib, "BCryptRemoveContextFunction");
            BCryptRemoveContextFunctionProvider = (void *)GetProcAddress(hLib, "BCryptRemoveContextFunctionProvider");
            BCryptResolveProviders = (void *)GetProcAddress(hLib, "BCryptResolveProviders");
            BCryptSecretAgreement = (void *)GetProcAddress(hLib, "BCryptSecretAgreement");
            BCryptSetAuditingInterface = (void *)GetProcAddress(hLib, "BCryptSetAuditingInterface");
            BCryptSetContextFunctionProperty = (void *)GetProcAddress(hLib, "BCryptSetContextFunctionProperty");
            BCryptSetProperty = (void *)GetProcAddress(hLib, "BCryptSetProperty");
            BCryptSignHash = (void *)GetProcAddress(hLib, "BCryptSignHash");
            BCryptUnregisterConfigChangeNotify = (void *)GetProcAddress(hLib, "BCryptUnregisterConfigChangeNotify");
            BCryptUnregisterProvider = (void *)GetProcAddress(hLib, "BCryptUnregisterProvider");
            BCryptVerifySignature = (void *)GetProcAddress(hLib, "BCryptVerifySignature");
        }
    }
    return hLib;
}

#endif
