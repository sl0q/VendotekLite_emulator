// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mifare/plus/auth.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mifare_2fplus_2fauth_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_mifare_2fplus_2fauth_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "mifare/plus/key_type.pb.h"
#include "mifare/plus/security_level.pb.h"
#include "mifare/av2/args.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_mifare_2fplus_2fauth_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mifare_2fplus_2fauth_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mifare_2fplus_2fauth_2eproto;
namespace mifare {
namespace plus {
namespace auth {
class ClearKey;
class ClearKeyDefaultTypeInternal;
extern ClearKeyDefaultTypeInternal _ClearKey_default_instance_;
class SamKey;
class SamKeyDefaultTypeInternal;
extern SamKeyDefaultTypeInternal _SamKey_default_instance_;
}  // namespace auth
}  // namespace plus
}  // namespace mifare
PROTOBUF_NAMESPACE_OPEN
template<> ::mifare::plus::auth::ClearKey* Arena::CreateMaybeMessage<::mifare::plus::auth::ClearKey>(Arena*);
template<> ::mifare::plus::auth::SamKey* Arena::CreateMaybeMessage<::mifare::plus::auth::SamKey>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mifare {
namespace plus {
namespace auth {

// ===================================================================

class ClearKey :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mifare.plus.auth.ClearKey) */ {
 public:
  ClearKey();
  virtual ~ClearKey();

  ClearKey(const ClearKey& from);
  ClearKey(ClearKey&& from) noexcept
    : ClearKey() {
    *this = ::std::move(from);
  }

  inline ClearKey& operator=(const ClearKey& from) {
    CopyFrom(from);
    return *this;
  }
  inline ClearKey& operator=(ClearKey&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ClearKey& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ClearKey* internal_default_instance() {
    return reinterpret_cast<const ClearKey*>(
               &_ClearKey_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ClearKey& a, ClearKey& b) {
    a.Swap(&b);
  }
  inline void Swap(ClearKey* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ClearKey* New() const final {
    return CreateMaybeMessage<ClearKey>(nullptr);
  }

  ClearKey* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ClearKey>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ClearKey& from);
  void MergeFrom(const ClearKey& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ClearKey* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mifare.plus.auth.ClearKey";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mifare_2fplus_2fauth_2eproto);
    return ::descriptor_table_mifare_2fplus_2fauth_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kClearKeyFieldNumber = 2,
    kDiversificationInputFieldNumber = 4,
    kKeyTypeFieldNumber = 1,
    kSecurityLevelFieldNumber = 3,
  };
  // required bytes clear_key = 2;
  bool has_clear_key() const;
  private:
  bool _internal_has_clear_key() const;
  public:
  void clear_clear_key();
  const std::string& clear_key() const;
  void set_clear_key(const std::string& value);
  void set_clear_key(std::string&& value);
  void set_clear_key(const char* value);
  void set_clear_key(const void* value, size_t size);
  std::string* mutable_clear_key();
  std::string* release_clear_key();
  void set_allocated_clear_key(std::string* clear_key);
  private:
  const std::string& _internal_clear_key() const;
  void _internal_set_clear_key(const std::string& value);
  std::string* _internal_mutable_clear_key();
  public:

  // optional bytes diversification_input = 4;
  bool has_diversification_input() const;
  private:
  bool _internal_has_diversification_input() const;
  public:
  void clear_diversification_input();
  const std::string& diversification_input() const;
  void set_diversification_input(const std::string& value);
  void set_diversification_input(std::string&& value);
  void set_diversification_input(const char* value);
  void set_diversification_input(const void* value, size_t size);
  std::string* mutable_diversification_input();
  std::string* release_diversification_input();
  void set_allocated_diversification_input(std::string* diversification_input);
  private:
  const std::string& _internal_diversification_input() const;
  void _internal_set_diversification_input(const std::string& value);
  std::string* _internal_mutable_diversification_input();
  public:

  // required .mifare.plus.key_type.KeyType key_type = 1;
  bool has_key_type() const;
  private:
  bool _internal_has_key_type() const;
  public:
  void clear_key_type();
  const ::mifare::plus::key_type::KeyType& key_type() const;
  ::mifare::plus::key_type::KeyType* release_key_type();
  ::mifare::plus::key_type::KeyType* mutable_key_type();
  void set_allocated_key_type(::mifare::plus::key_type::KeyType* key_type);
  private:
  const ::mifare::plus::key_type::KeyType& _internal_key_type() const;
  ::mifare::plus::key_type::KeyType* _internal_mutable_key_type();
  public:

  // optional .mifare.plus.security_level.SecurityLevel security_level = 3 [default = SL3];
  bool has_security_level() const;
  private:
  bool _internal_has_security_level() const;
  public:
  void clear_security_level();
  ::mifare::plus::security_level::SecurityLevel security_level() const;
  void set_security_level(::mifare::plus::security_level::SecurityLevel value);
  private:
  ::mifare::plus::security_level::SecurityLevel _internal_security_level() const;
  void _internal_set_security_level(::mifare::plus::security_level::SecurityLevel value);
  public:

  // @@protoc_insertion_point(class_scope:mifare.plus.auth.ClearKey)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr clear_key_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr diversification_input_;
  ::mifare::plus::key_type::KeyType* key_type_;
  int security_level_;
  friend struct ::TableStruct_mifare_2fplus_2fauth_2eproto;
};
// -------------------------------------------------------------------

class SamKey :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mifare.plus.auth.SamKey) */ {
 public:
  SamKey();
  virtual ~SamKey();

  SamKey(const SamKey& from);
  SamKey(SamKey&& from) noexcept
    : SamKey() {
    *this = ::std::move(from);
  }

  inline SamKey& operator=(const SamKey& from) {
    CopyFrom(from);
    return *this;
  }
  inline SamKey& operator=(SamKey&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SamKey& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SamKey* internal_default_instance() {
    return reinterpret_cast<const SamKey*>(
               &_SamKey_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(SamKey& a, SamKey& b) {
    a.Swap(&b);
  }
  inline void Swap(SamKey* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SamKey* New() const final {
    return CreateMaybeMessage<SamKey>(nullptr);
  }

  SamKey* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SamKey>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SamKey& from);
  void MergeFrom(const SamKey& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SamKey* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mifare.plus.auth.SamKey";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mifare_2fplus_2fauth_2eproto);
    return ::descriptor_table_mifare_2fplus_2fauth_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDiversificationInputFieldNumber = 4,
    kKeyTypeFieldNumber = 1,
    kAv2ArgsFieldNumber = 2,
    kSecurityLevelFieldNumber = 3,
  };
  // optional bytes diversification_input = 4;
  bool has_diversification_input() const;
  private:
  bool _internal_has_diversification_input() const;
  public:
  void clear_diversification_input();
  const std::string& diversification_input() const;
  void set_diversification_input(const std::string& value);
  void set_diversification_input(std::string&& value);
  void set_diversification_input(const char* value);
  void set_diversification_input(const void* value, size_t size);
  std::string* mutable_diversification_input();
  std::string* release_diversification_input();
  void set_allocated_diversification_input(std::string* diversification_input);
  private:
  const std::string& _internal_diversification_input() const;
  void _internal_set_diversification_input(const std::string& value);
  std::string* _internal_mutable_diversification_input();
  public:

  // required .mifare.plus.key_type.KeyType key_type = 1;
  bool has_key_type() const;
  private:
  bool _internal_has_key_type() const;
  public:
  void clear_key_type();
  const ::mifare::plus::key_type::KeyType& key_type() const;
  ::mifare::plus::key_type::KeyType* release_key_type();
  ::mifare::plus::key_type::KeyType* mutable_key_type();
  void set_allocated_key_type(::mifare::plus::key_type::KeyType* key_type);
  private:
  const ::mifare::plus::key_type::KeyType& _internal_key_type() const;
  ::mifare::plus::key_type::KeyType* _internal_mutable_key_type();
  public:

  // required .mifare.av2.args.AuthenticationArguments av2_args = 2;
  bool has_av2_args() const;
  private:
  bool _internal_has_av2_args() const;
  public:
  void clear_av2_args();
  const ::mifare::av2::args::AuthenticationArguments& av2_args() const;
  ::mifare::av2::args::AuthenticationArguments* release_av2_args();
  ::mifare::av2::args::AuthenticationArguments* mutable_av2_args();
  void set_allocated_av2_args(::mifare::av2::args::AuthenticationArguments* av2_args);
  private:
  const ::mifare::av2::args::AuthenticationArguments& _internal_av2_args() const;
  ::mifare::av2::args::AuthenticationArguments* _internal_mutable_av2_args();
  public:

  // optional .mifare.plus.security_level.SecurityLevel security_level = 3 [default = SL3];
  bool has_security_level() const;
  private:
  bool _internal_has_security_level() const;
  public:
  void clear_security_level();
  ::mifare::plus::security_level::SecurityLevel security_level() const;
  void set_security_level(::mifare::plus::security_level::SecurityLevel value);
  private:
  ::mifare::plus::security_level::SecurityLevel _internal_security_level() const;
  void _internal_set_security_level(::mifare::plus::security_level::SecurityLevel value);
  public:

  // @@protoc_insertion_point(class_scope:mifare.plus.auth.SamKey)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr diversification_input_;
  ::mifare::plus::key_type::KeyType* key_type_;
  ::mifare::av2::args::AuthenticationArguments* av2_args_;
  int security_level_;
  friend struct ::TableStruct_mifare_2fplus_2fauth_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ClearKey

// required .mifare.plus.key_type.KeyType key_type = 1;
inline bool ClearKey::_internal_has_key_type() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  PROTOBUF_ASSUME(!value || key_type_ != nullptr);
  return value;
}
inline bool ClearKey::has_key_type() const {
  return _internal_has_key_type();
}
inline const ::mifare::plus::key_type::KeyType& ClearKey::_internal_key_type() const {
  const ::mifare::plus::key_type::KeyType* p = key_type_;
  return p != nullptr ? *p : *reinterpret_cast<const ::mifare::plus::key_type::KeyType*>(
      &::mifare::plus::key_type::_KeyType_default_instance_);
}
inline const ::mifare::plus::key_type::KeyType& ClearKey::key_type() const {
  // @@protoc_insertion_point(field_get:mifare.plus.auth.ClearKey.key_type)
  return _internal_key_type();
}
inline ::mifare::plus::key_type::KeyType* ClearKey::release_key_type() {
  // @@protoc_insertion_point(field_release:mifare.plus.auth.ClearKey.key_type)
  _has_bits_[0] &= ~0x00000004u;
  ::mifare::plus::key_type::KeyType* temp = key_type_;
  key_type_ = nullptr;
  return temp;
}
inline ::mifare::plus::key_type::KeyType* ClearKey::_internal_mutable_key_type() {
  _has_bits_[0] |= 0x00000004u;
  if (key_type_ == nullptr) {
    auto* p = CreateMaybeMessage<::mifare::plus::key_type::KeyType>(GetArenaNoVirtual());
    key_type_ = p;
  }
  return key_type_;
}
inline ::mifare::plus::key_type::KeyType* ClearKey::mutable_key_type() {
  // @@protoc_insertion_point(field_mutable:mifare.plus.auth.ClearKey.key_type)
  return _internal_mutable_key_type();
}
inline void ClearKey::set_allocated_key_type(::mifare::plus::key_type::KeyType* key_type) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(key_type_);
  }
  if (key_type) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      key_type = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, key_type, submessage_arena);
    }
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  key_type_ = key_type;
  // @@protoc_insertion_point(field_set_allocated:mifare.plus.auth.ClearKey.key_type)
}

// required bytes clear_key = 2;
inline bool ClearKey::_internal_has_clear_key() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ClearKey::has_clear_key() const {
  return _internal_has_clear_key();
}
inline void ClearKey::clear_clear_key() {
  clear_key_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& ClearKey::clear_key() const {
  // @@protoc_insertion_point(field_get:mifare.plus.auth.ClearKey.clear_key)
  return _internal_clear_key();
}
inline void ClearKey::set_clear_key(const std::string& value) {
  _internal_set_clear_key(value);
  // @@protoc_insertion_point(field_set:mifare.plus.auth.ClearKey.clear_key)
}
inline std::string* ClearKey::mutable_clear_key() {
  // @@protoc_insertion_point(field_mutable:mifare.plus.auth.ClearKey.clear_key)
  return _internal_mutable_clear_key();
}
inline const std::string& ClearKey::_internal_clear_key() const {
  return clear_key_.GetNoArena();
}
inline void ClearKey::_internal_set_clear_key(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  clear_key_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ClearKey::set_clear_key(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  clear_key_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:mifare.plus.auth.ClearKey.clear_key)
}
inline void ClearKey::set_clear_key(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  clear_key_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:mifare.plus.auth.ClearKey.clear_key)
}
inline void ClearKey::set_clear_key(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  clear_key_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:mifare.plus.auth.ClearKey.clear_key)
}
inline std::string* ClearKey::_internal_mutable_clear_key() {
  _has_bits_[0] |= 0x00000001u;
  return clear_key_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ClearKey::release_clear_key() {
  // @@protoc_insertion_point(field_release:mifare.plus.auth.ClearKey.clear_key)
  if (!_internal_has_clear_key()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return clear_key_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ClearKey::set_allocated_clear_key(std::string* clear_key) {
  if (clear_key != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  clear_key_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), clear_key);
  // @@protoc_insertion_point(field_set_allocated:mifare.plus.auth.ClearKey.clear_key)
}

// optional .mifare.plus.security_level.SecurityLevel security_level = 3 [default = SL3];
inline bool ClearKey::_internal_has_security_level() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool ClearKey::has_security_level() const {
  return _internal_has_security_level();
}
inline void ClearKey::clear_security_level() {
  security_level_ = 3;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::mifare::plus::security_level::SecurityLevel ClearKey::_internal_security_level() const {
  return static_cast< ::mifare::plus::security_level::SecurityLevel >(security_level_);
}
inline ::mifare::plus::security_level::SecurityLevel ClearKey::security_level() const {
  // @@protoc_insertion_point(field_get:mifare.plus.auth.ClearKey.security_level)
  return _internal_security_level();
}
inline void ClearKey::_internal_set_security_level(::mifare::plus::security_level::SecurityLevel value) {
  assert(::mifare::plus::security_level::SecurityLevel_IsValid(value));
  _has_bits_[0] |= 0x00000008u;
  security_level_ = value;
}
inline void ClearKey::set_security_level(::mifare::plus::security_level::SecurityLevel value) {
  _internal_set_security_level(value);
  // @@protoc_insertion_point(field_set:mifare.plus.auth.ClearKey.security_level)
}

// optional bytes diversification_input = 4;
inline bool ClearKey::_internal_has_diversification_input() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ClearKey::has_diversification_input() const {
  return _internal_has_diversification_input();
}
inline void ClearKey::clear_diversification_input() {
  diversification_input_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& ClearKey::diversification_input() const {
  // @@protoc_insertion_point(field_get:mifare.plus.auth.ClearKey.diversification_input)
  return _internal_diversification_input();
}
inline void ClearKey::set_diversification_input(const std::string& value) {
  _internal_set_diversification_input(value);
  // @@protoc_insertion_point(field_set:mifare.plus.auth.ClearKey.diversification_input)
}
inline std::string* ClearKey::mutable_diversification_input() {
  // @@protoc_insertion_point(field_mutable:mifare.plus.auth.ClearKey.diversification_input)
  return _internal_mutable_diversification_input();
}
inline const std::string& ClearKey::_internal_diversification_input() const {
  return diversification_input_.GetNoArena();
}
inline void ClearKey::_internal_set_diversification_input(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  diversification_input_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ClearKey::set_diversification_input(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  diversification_input_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:mifare.plus.auth.ClearKey.diversification_input)
}
inline void ClearKey::set_diversification_input(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  diversification_input_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:mifare.plus.auth.ClearKey.diversification_input)
}
inline void ClearKey::set_diversification_input(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  diversification_input_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:mifare.plus.auth.ClearKey.diversification_input)
}
inline std::string* ClearKey::_internal_mutable_diversification_input() {
  _has_bits_[0] |= 0x00000002u;
  return diversification_input_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ClearKey::release_diversification_input() {
  // @@protoc_insertion_point(field_release:mifare.plus.auth.ClearKey.diversification_input)
  if (!_internal_has_diversification_input()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return diversification_input_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ClearKey::set_allocated_diversification_input(std::string* diversification_input) {
  if (diversification_input != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  diversification_input_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), diversification_input);
  // @@protoc_insertion_point(field_set_allocated:mifare.plus.auth.ClearKey.diversification_input)
}

// -------------------------------------------------------------------

// SamKey

// required .mifare.plus.key_type.KeyType key_type = 1;
inline bool SamKey::_internal_has_key_type() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || key_type_ != nullptr);
  return value;
}
inline bool SamKey::has_key_type() const {
  return _internal_has_key_type();
}
inline const ::mifare::plus::key_type::KeyType& SamKey::_internal_key_type() const {
  const ::mifare::plus::key_type::KeyType* p = key_type_;
  return p != nullptr ? *p : *reinterpret_cast<const ::mifare::plus::key_type::KeyType*>(
      &::mifare::plus::key_type::_KeyType_default_instance_);
}
inline const ::mifare::plus::key_type::KeyType& SamKey::key_type() const {
  // @@protoc_insertion_point(field_get:mifare.plus.auth.SamKey.key_type)
  return _internal_key_type();
}
inline ::mifare::plus::key_type::KeyType* SamKey::release_key_type() {
  // @@protoc_insertion_point(field_release:mifare.plus.auth.SamKey.key_type)
  _has_bits_[0] &= ~0x00000002u;
  ::mifare::plus::key_type::KeyType* temp = key_type_;
  key_type_ = nullptr;
  return temp;
}
inline ::mifare::plus::key_type::KeyType* SamKey::_internal_mutable_key_type() {
  _has_bits_[0] |= 0x00000002u;
  if (key_type_ == nullptr) {
    auto* p = CreateMaybeMessage<::mifare::plus::key_type::KeyType>(GetArenaNoVirtual());
    key_type_ = p;
  }
  return key_type_;
}
inline ::mifare::plus::key_type::KeyType* SamKey::mutable_key_type() {
  // @@protoc_insertion_point(field_mutable:mifare.plus.auth.SamKey.key_type)
  return _internal_mutable_key_type();
}
inline void SamKey::set_allocated_key_type(::mifare::plus::key_type::KeyType* key_type) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(key_type_);
  }
  if (key_type) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      key_type = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, key_type, submessage_arena);
    }
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  key_type_ = key_type;
  // @@protoc_insertion_point(field_set_allocated:mifare.plus.auth.SamKey.key_type)
}

// required .mifare.av2.args.AuthenticationArguments av2_args = 2;
inline bool SamKey::_internal_has_av2_args() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  PROTOBUF_ASSUME(!value || av2_args_ != nullptr);
  return value;
}
inline bool SamKey::has_av2_args() const {
  return _internal_has_av2_args();
}
inline const ::mifare::av2::args::AuthenticationArguments& SamKey::_internal_av2_args() const {
  const ::mifare::av2::args::AuthenticationArguments* p = av2_args_;
  return p != nullptr ? *p : *reinterpret_cast<const ::mifare::av2::args::AuthenticationArguments*>(
      &::mifare::av2::args::_AuthenticationArguments_default_instance_);
}
inline const ::mifare::av2::args::AuthenticationArguments& SamKey::av2_args() const {
  // @@protoc_insertion_point(field_get:mifare.plus.auth.SamKey.av2_args)
  return _internal_av2_args();
}
inline ::mifare::av2::args::AuthenticationArguments* SamKey::release_av2_args() {
  // @@protoc_insertion_point(field_release:mifare.plus.auth.SamKey.av2_args)
  _has_bits_[0] &= ~0x00000004u;
  ::mifare::av2::args::AuthenticationArguments* temp = av2_args_;
  av2_args_ = nullptr;
  return temp;
}
inline ::mifare::av2::args::AuthenticationArguments* SamKey::_internal_mutable_av2_args() {
  _has_bits_[0] |= 0x00000004u;
  if (av2_args_ == nullptr) {
    auto* p = CreateMaybeMessage<::mifare::av2::args::AuthenticationArguments>(GetArenaNoVirtual());
    av2_args_ = p;
  }
  return av2_args_;
}
inline ::mifare::av2::args::AuthenticationArguments* SamKey::mutable_av2_args() {
  // @@protoc_insertion_point(field_mutable:mifare.plus.auth.SamKey.av2_args)
  return _internal_mutable_av2_args();
}
inline void SamKey::set_allocated_av2_args(::mifare::av2::args::AuthenticationArguments* av2_args) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(av2_args_);
  }
  if (av2_args) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      av2_args = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, av2_args, submessage_arena);
    }
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  av2_args_ = av2_args;
  // @@protoc_insertion_point(field_set_allocated:mifare.plus.auth.SamKey.av2_args)
}

// optional .mifare.plus.security_level.SecurityLevel security_level = 3 [default = SL3];
inline bool SamKey::_internal_has_security_level() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool SamKey::has_security_level() const {
  return _internal_has_security_level();
}
inline void SamKey::clear_security_level() {
  security_level_ = 3;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::mifare::plus::security_level::SecurityLevel SamKey::_internal_security_level() const {
  return static_cast< ::mifare::plus::security_level::SecurityLevel >(security_level_);
}
inline ::mifare::plus::security_level::SecurityLevel SamKey::security_level() const {
  // @@protoc_insertion_point(field_get:mifare.plus.auth.SamKey.security_level)
  return _internal_security_level();
}
inline void SamKey::_internal_set_security_level(::mifare::plus::security_level::SecurityLevel value) {
  assert(::mifare::plus::security_level::SecurityLevel_IsValid(value));
  _has_bits_[0] |= 0x00000008u;
  security_level_ = value;
}
inline void SamKey::set_security_level(::mifare::plus::security_level::SecurityLevel value) {
  _internal_set_security_level(value);
  // @@protoc_insertion_point(field_set:mifare.plus.auth.SamKey.security_level)
}

// optional bytes diversification_input = 4;
inline bool SamKey::_internal_has_diversification_input() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool SamKey::has_diversification_input() const {
  return _internal_has_diversification_input();
}
inline void SamKey::clear_diversification_input() {
  diversification_input_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& SamKey::diversification_input() const {
  // @@protoc_insertion_point(field_get:mifare.plus.auth.SamKey.diversification_input)
  return _internal_diversification_input();
}
inline void SamKey::set_diversification_input(const std::string& value) {
  _internal_set_diversification_input(value);
  // @@protoc_insertion_point(field_set:mifare.plus.auth.SamKey.diversification_input)
}
inline std::string* SamKey::mutable_diversification_input() {
  // @@protoc_insertion_point(field_mutable:mifare.plus.auth.SamKey.diversification_input)
  return _internal_mutable_diversification_input();
}
inline const std::string& SamKey::_internal_diversification_input() const {
  return diversification_input_.GetNoArena();
}
inline void SamKey::_internal_set_diversification_input(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  diversification_input_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void SamKey::set_diversification_input(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  diversification_input_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:mifare.plus.auth.SamKey.diversification_input)
}
inline void SamKey::set_diversification_input(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  diversification_input_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:mifare.plus.auth.SamKey.diversification_input)
}
inline void SamKey::set_diversification_input(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  diversification_input_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:mifare.plus.auth.SamKey.diversification_input)
}
inline std::string* SamKey::_internal_mutable_diversification_input() {
  _has_bits_[0] |= 0x00000001u;
  return diversification_input_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* SamKey::release_diversification_input() {
  // @@protoc_insertion_point(field_release:mifare.plus.auth.SamKey.diversification_input)
  if (!_internal_has_diversification_input()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return diversification_input_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void SamKey::set_allocated_diversification_input(std::string* diversification_input) {
  if (diversification_input != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  diversification_input_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), diversification_input);
  // @@protoc_insertion_point(field_set_allocated:mifare.plus.auth.SamKey.diversification_input)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace auth
}  // namespace plus
}  // namespace mifare

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_mifare_2fplus_2fauth_2eproto