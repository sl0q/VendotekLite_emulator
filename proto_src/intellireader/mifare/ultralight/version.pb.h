// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mifare/ultralight/version.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mifare_2fultralight_2fversion_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_mifare_2fultralight_2fversion_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_mifare_2fultralight_2fversion_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mifare_2fultralight_2fversion_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mifare_2fultralight_2fversion_2eproto;
namespace mifare {
namespace ultralight {
namespace version {
class GetVersion;
class GetVersionDefaultTypeInternal;
extern GetVersionDefaultTypeInternal _GetVersion_default_instance_;
class Version;
class VersionDefaultTypeInternal;
extern VersionDefaultTypeInternal _Version_default_instance_;
}  // namespace version
}  // namespace ultralight
}  // namespace mifare
PROTOBUF_NAMESPACE_OPEN
template<> ::mifare::ultralight::version::GetVersion* Arena::CreateMaybeMessage<::mifare::ultralight::version::GetVersion>(Arena*);
template<> ::mifare::ultralight::version::Version* Arena::CreateMaybeMessage<::mifare::ultralight::version::Version>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mifare {
namespace ultralight {
namespace version {

// ===================================================================

class GetVersion :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mifare.ultralight.version.GetVersion) */ {
 public:
  GetVersion();
  virtual ~GetVersion();

  GetVersion(const GetVersion& from);
  GetVersion(GetVersion&& from) noexcept
    : GetVersion() {
    *this = ::std::move(from);
  }

  inline GetVersion& operator=(const GetVersion& from) {
    CopyFrom(from);
    return *this;
  }
  inline GetVersion& operator=(GetVersion&& from) noexcept {
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
  static const GetVersion& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetVersion* internal_default_instance() {
    return reinterpret_cast<const GetVersion*>(
               &_GetVersion_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GetVersion& a, GetVersion& b) {
    a.Swap(&b);
  }
  inline void Swap(GetVersion* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GetVersion* New() const final {
    return CreateMaybeMessage<GetVersion>(nullptr);
  }

  GetVersion* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GetVersion>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GetVersion& from);
  void MergeFrom(const GetVersion& from);
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
  void InternalSwap(GetVersion* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mifare.ultralight.version.GetVersion";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mifare_2fultralight_2fversion_2eproto);
    return ::descriptor_table_mifare_2fultralight_2fversion_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:mifare.ultralight.version.GetVersion)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_mifare_2fultralight_2fversion_2eproto;
};
// -------------------------------------------------------------------

class Version :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mifare.ultralight.version.Version) */ {
 public:
  Version();
  virtual ~Version();

  Version(const Version& from);
  Version(Version&& from) noexcept
    : Version() {
    *this = ::std::move(from);
  }

  inline Version& operator=(const Version& from) {
    CopyFrom(from);
    return *this;
  }
  inline Version& operator=(Version&& from) noexcept {
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
  static const Version& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Version* internal_default_instance() {
    return reinterpret_cast<const Version*>(
               &_Version_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Version& a, Version& b) {
    a.Swap(&b);
  }
  inline void Swap(Version* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Version* New() const final {
    return CreateMaybeMessage<Version>(nullptr);
  }

  Version* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Version>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Version& from);
  void MergeFrom(const Version& from);
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
  void InternalSwap(Version* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mifare.ultralight.version.Version";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mifare_2fultralight_2fversion_2eproto);
    return ::descriptor_table_mifare_2fultralight_2fversion_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRawVersionDataFieldNumber = 1,
  };
  // required bytes raw_version_data = 1;
  bool has_raw_version_data() const;
  private:
  bool _internal_has_raw_version_data() const;
  public:
  void clear_raw_version_data();
  const std::string& raw_version_data() const;
  void set_raw_version_data(const std::string& value);
  void set_raw_version_data(std::string&& value);
  void set_raw_version_data(const char* value);
  void set_raw_version_data(const void* value, size_t size);
  std::string* mutable_raw_version_data();
  std::string* release_raw_version_data();
  void set_allocated_raw_version_data(std::string* raw_version_data);
  private:
  const std::string& _internal_raw_version_data() const;
  void _internal_set_raw_version_data(const std::string& value);
  std::string* _internal_mutable_raw_version_data();
  public:

  // @@protoc_insertion_point(class_scope:mifare.ultralight.version.Version)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr raw_version_data_;
  friend struct ::TableStruct_mifare_2fultralight_2fversion_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GetVersion

// -------------------------------------------------------------------

// Version

// required bytes raw_version_data = 1;
inline bool Version::_internal_has_raw_version_data() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Version::has_raw_version_data() const {
  return _internal_has_raw_version_data();
}
inline void Version::clear_raw_version_data() {
  raw_version_data_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Version::raw_version_data() const {
  // @@protoc_insertion_point(field_get:mifare.ultralight.version.Version.raw_version_data)
  return _internal_raw_version_data();
}
inline void Version::set_raw_version_data(const std::string& value) {
  _internal_set_raw_version_data(value);
  // @@protoc_insertion_point(field_set:mifare.ultralight.version.Version.raw_version_data)
}
inline std::string* Version::mutable_raw_version_data() {
  // @@protoc_insertion_point(field_mutable:mifare.ultralight.version.Version.raw_version_data)
  return _internal_mutable_raw_version_data();
}
inline const std::string& Version::_internal_raw_version_data() const {
  return raw_version_data_.GetNoArena();
}
inline void Version::_internal_set_raw_version_data(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  raw_version_data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Version::set_raw_version_data(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  raw_version_data_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:mifare.ultralight.version.Version.raw_version_data)
}
inline void Version::set_raw_version_data(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  raw_version_data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:mifare.ultralight.version.Version.raw_version_data)
}
inline void Version::set_raw_version_data(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  raw_version_data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:mifare.ultralight.version.Version.raw_version_data)
}
inline std::string* Version::_internal_mutable_raw_version_data() {
  _has_bits_[0] |= 0x00000001u;
  return raw_version_data_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Version::release_raw_version_data() {
  // @@protoc_insertion_point(field_release:mifare.ultralight.version.Version.raw_version_data)
  if (!_internal_has_raw_version_data()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return raw_version_data_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Version::set_allocated_raw_version_data(std::string* raw_version_data) {
  if (raw_version_data != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  raw_version_data_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), raw_version_data);
  // @@protoc_insertion_point(field_set_allocated:mifare.ultralight.version.Version.raw_version_data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace version
}  // namespace ultralight
}  // namespace mifare

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_mifare_2fultralight_2fversion_2eproto