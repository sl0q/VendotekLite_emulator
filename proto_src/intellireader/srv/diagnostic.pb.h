// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: srv/diagnostic.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_srv_2fdiagnostic_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_srv_2fdiagnostic_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_srv_2fdiagnostic_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_srv_2fdiagnostic_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_srv_2fdiagnostic_2eproto;
namespace srv {
namespace diagnostic {
class DiagnosticInfo;
class DiagnosticInfoDefaultTypeInternal;
extern DiagnosticInfoDefaultTypeInternal _DiagnosticInfo_default_instance_;
class GetDiagnostic;
class GetDiagnosticDefaultTypeInternal;
extern GetDiagnosticDefaultTypeInternal _GetDiagnostic_default_instance_;
}  // namespace diagnostic
}  // namespace srv
PROTOBUF_NAMESPACE_OPEN
template<> ::srv::diagnostic::DiagnosticInfo* Arena::CreateMaybeMessage<::srv::diagnostic::DiagnosticInfo>(Arena*);
template<> ::srv::diagnostic::GetDiagnostic* Arena::CreateMaybeMessage<::srv::diagnostic::GetDiagnostic>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace srv {
namespace diagnostic {

// ===================================================================

class GetDiagnostic :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:srv.diagnostic.GetDiagnostic) */ {
 public:
  GetDiagnostic();
  virtual ~GetDiagnostic();

  GetDiagnostic(const GetDiagnostic& from);
  GetDiagnostic(GetDiagnostic&& from) noexcept
    : GetDiagnostic() {
    *this = ::std::move(from);
  }

  inline GetDiagnostic& operator=(const GetDiagnostic& from) {
    CopyFrom(from);
    return *this;
  }
  inline GetDiagnostic& operator=(GetDiagnostic&& from) noexcept {
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
  static const GetDiagnostic& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetDiagnostic* internal_default_instance() {
    return reinterpret_cast<const GetDiagnostic*>(
               &_GetDiagnostic_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GetDiagnostic& a, GetDiagnostic& b) {
    a.Swap(&b);
  }
  inline void Swap(GetDiagnostic* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GetDiagnostic* New() const final {
    return CreateMaybeMessage<GetDiagnostic>(nullptr);
  }

  GetDiagnostic* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GetDiagnostic>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GetDiagnostic& from);
  void MergeFrom(const GetDiagnostic& from);
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
  void InternalSwap(GetDiagnostic* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "srv.diagnostic.GetDiagnostic";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_srv_2fdiagnostic_2eproto);
    return ::descriptor_table_srv_2fdiagnostic_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:srv.diagnostic.GetDiagnostic)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_srv_2fdiagnostic_2eproto;
};
// -------------------------------------------------------------------

class DiagnosticInfo :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:srv.diagnostic.DiagnosticInfo) */ {
 public:
  DiagnosticInfo();
  virtual ~DiagnosticInfo();

  DiagnosticInfo(const DiagnosticInfo& from);
  DiagnosticInfo(DiagnosticInfo&& from) noexcept
    : DiagnosticInfo() {
    *this = ::std::move(from);
  }

  inline DiagnosticInfo& operator=(const DiagnosticInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline DiagnosticInfo& operator=(DiagnosticInfo&& from) noexcept {
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
  static const DiagnosticInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DiagnosticInfo* internal_default_instance() {
    return reinterpret_cast<const DiagnosticInfo*>(
               &_DiagnosticInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(DiagnosticInfo& a, DiagnosticInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(DiagnosticInfo* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline DiagnosticInfo* New() const final {
    return CreateMaybeMessage<DiagnosticInfo>(nullptr);
  }

  DiagnosticInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<DiagnosticInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const DiagnosticInfo& from);
  void MergeFrom(const DiagnosticInfo& from);
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
  void InternalSwap(DiagnosticInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "srv.diagnostic.DiagnosticInfo";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_srv_2fdiagnostic_2eproto);
    return ::descriptor_table_srv_2fdiagnostic_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNfcErrorFieldNumber = 1,
    kMcuErrorFieldNumber = 2,
    kTouchscreenErrorFieldNumber = 3,
    kStorageErrorFieldNumber = 4,
    kLastRebootReasonFieldNumber = 5,
  };
  // optional string nfc_error = 1;
  bool has_nfc_error() const;
  private:
  bool _internal_has_nfc_error() const;
  public:
  void clear_nfc_error();
  const std::string& nfc_error() const;
  void set_nfc_error(const std::string& value);
  void set_nfc_error(std::string&& value);
  void set_nfc_error(const char* value);
  void set_nfc_error(const char* value, size_t size);
  std::string* mutable_nfc_error();
  std::string* release_nfc_error();
  void set_allocated_nfc_error(std::string* nfc_error);
  private:
  const std::string& _internal_nfc_error() const;
  void _internal_set_nfc_error(const std::string& value);
  std::string* _internal_mutable_nfc_error();
  public:

  // optional string mcu_error = 2;
  bool has_mcu_error() const;
  private:
  bool _internal_has_mcu_error() const;
  public:
  void clear_mcu_error();
  const std::string& mcu_error() const;
  void set_mcu_error(const std::string& value);
  void set_mcu_error(std::string&& value);
  void set_mcu_error(const char* value);
  void set_mcu_error(const char* value, size_t size);
  std::string* mutable_mcu_error();
  std::string* release_mcu_error();
  void set_allocated_mcu_error(std::string* mcu_error);
  private:
  const std::string& _internal_mcu_error() const;
  void _internal_set_mcu_error(const std::string& value);
  std::string* _internal_mutable_mcu_error();
  public:

  // optional string touchscreen_error = 3;
  bool has_touchscreen_error() const;
  private:
  bool _internal_has_touchscreen_error() const;
  public:
  void clear_touchscreen_error();
  const std::string& touchscreen_error() const;
  void set_touchscreen_error(const std::string& value);
  void set_touchscreen_error(std::string&& value);
  void set_touchscreen_error(const char* value);
  void set_touchscreen_error(const char* value, size_t size);
  std::string* mutable_touchscreen_error();
  std::string* release_touchscreen_error();
  void set_allocated_touchscreen_error(std::string* touchscreen_error);
  private:
  const std::string& _internal_touchscreen_error() const;
  void _internal_set_touchscreen_error(const std::string& value);
  std::string* _internal_mutable_touchscreen_error();
  public:

  // optional string storage_error = 4;
  bool has_storage_error() const;
  private:
  bool _internal_has_storage_error() const;
  public:
  void clear_storage_error();
  const std::string& storage_error() const;
  void set_storage_error(const std::string& value);
  void set_storage_error(std::string&& value);
  void set_storage_error(const char* value);
  void set_storage_error(const char* value, size_t size);
  std::string* mutable_storage_error();
  std::string* release_storage_error();
  void set_allocated_storage_error(std::string* storage_error);
  private:
  const std::string& _internal_storage_error() const;
  void _internal_set_storage_error(const std::string& value);
  std::string* _internal_mutable_storage_error();
  public:

  // optional string last_reboot_reason = 5;
  bool has_last_reboot_reason() const;
  private:
  bool _internal_has_last_reboot_reason() const;
  public:
  void clear_last_reboot_reason();
  const std::string& last_reboot_reason() const;
  void set_last_reboot_reason(const std::string& value);
  void set_last_reboot_reason(std::string&& value);
  void set_last_reboot_reason(const char* value);
  void set_last_reboot_reason(const char* value, size_t size);
  std::string* mutable_last_reboot_reason();
  std::string* release_last_reboot_reason();
  void set_allocated_last_reboot_reason(std::string* last_reboot_reason);
  private:
  const std::string& _internal_last_reboot_reason() const;
  void _internal_set_last_reboot_reason(const std::string& value);
  std::string* _internal_mutable_last_reboot_reason();
  public:

  // @@protoc_insertion_point(class_scope:srv.diagnostic.DiagnosticInfo)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr nfc_error_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr mcu_error_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr touchscreen_error_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr storage_error_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr last_reboot_reason_;
  friend struct ::TableStruct_srv_2fdiagnostic_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GetDiagnostic

// -------------------------------------------------------------------

// DiagnosticInfo

// optional string nfc_error = 1;
inline bool DiagnosticInfo::_internal_has_nfc_error() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool DiagnosticInfo::has_nfc_error() const {
  return _internal_has_nfc_error();
}
inline void DiagnosticInfo::clear_nfc_error() {
  nfc_error_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& DiagnosticInfo::nfc_error() const {
  // @@protoc_insertion_point(field_get:srv.diagnostic.DiagnosticInfo.nfc_error)
  return _internal_nfc_error();
}
inline void DiagnosticInfo::set_nfc_error(const std::string& value) {
  _internal_set_nfc_error(value);
  // @@protoc_insertion_point(field_set:srv.diagnostic.DiagnosticInfo.nfc_error)
}
inline std::string* DiagnosticInfo::mutable_nfc_error() {
  // @@protoc_insertion_point(field_mutable:srv.diagnostic.DiagnosticInfo.nfc_error)
  return _internal_mutable_nfc_error();
}
inline const std::string& DiagnosticInfo::_internal_nfc_error() const {
  return nfc_error_.GetNoArena();
}
inline void DiagnosticInfo::_internal_set_nfc_error(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  nfc_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void DiagnosticInfo::set_nfc_error(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  nfc_error_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:srv.diagnostic.DiagnosticInfo.nfc_error)
}
inline void DiagnosticInfo::set_nfc_error(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  nfc_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:srv.diagnostic.DiagnosticInfo.nfc_error)
}
inline void DiagnosticInfo::set_nfc_error(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  nfc_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:srv.diagnostic.DiagnosticInfo.nfc_error)
}
inline std::string* DiagnosticInfo::_internal_mutable_nfc_error() {
  _has_bits_[0] |= 0x00000001u;
  return nfc_error_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* DiagnosticInfo::release_nfc_error() {
  // @@protoc_insertion_point(field_release:srv.diagnostic.DiagnosticInfo.nfc_error)
  if (!_internal_has_nfc_error()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return nfc_error_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void DiagnosticInfo::set_allocated_nfc_error(std::string* nfc_error) {
  if (nfc_error != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  nfc_error_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), nfc_error);
  // @@protoc_insertion_point(field_set_allocated:srv.diagnostic.DiagnosticInfo.nfc_error)
}

// optional string mcu_error = 2;
inline bool DiagnosticInfo::_internal_has_mcu_error() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool DiagnosticInfo::has_mcu_error() const {
  return _internal_has_mcu_error();
}
inline void DiagnosticInfo::clear_mcu_error() {
  mcu_error_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& DiagnosticInfo::mcu_error() const {
  // @@protoc_insertion_point(field_get:srv.diagnostic.DiagnosticInfo.mcu_error)
  return _internal_mcu_error();
}
inline void DiagnosticInfo::set_mcu_error(const std::string& value) {
  _internal_set_mcu_error(value);
  // @@protoc_insertion_point(field_set:srv.diagnostic.DiagnosticInfo.mcu_error)
}
inline std::string* DiagnosticInfo::mutable_mcu_error() {
  // @@protoc_insertion_point(field_mutable:srv.diagnostic.DiagnosticInfo.mcu_error)
  return _internal_mutable_mcu_error();
}
inline const std::string& DiagnosticInfo::_internal_mcu_error() const {
  return mcu_error_.GetNoArena();
}
inline void DiagnosticInfo::_internal_set_mcu_error(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  mcu_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void DiagnosticInfo::set_mcu_error(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  mcu_error_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:srv.diagnostic.DiagnosticInfo.mcu_error)
}
inline void DiagnosticInfo::set_mcu_error(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  mcu_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:srv.diagnostic.DiagnosticInfo.mcu_error)
}
inline void DiagnosticInfo::set_mcu_error(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  mcu_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:srv.diagnostic.DiagnosticInfo.mcu_error)
}
inline std::string* DiagnosticInfo::_internal_mutable_mcu_error() {
  _has_bits_[0] |= 0x00000002u;
  return mcu_error_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* DiagnosticInfo::release_mcu_error() {
  // @@protoc_insertion_point(field_release:srv.diagnostic.DiagnosticInfo.mcu_error)
  if (!_internal_has_mcu_error()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return mcu_error_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void DiagnosticInfo::set_allocated_mcu_error(std::string* mcu_error) {
  if (mcu_error != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  mcu_error_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), mcu_error);
  // @@protoc_insertion_point(field_set_allocated:srv.diagnostic.DiagnosticInfo.mcu_error)
}

// optional string touchscreen_error = 3;
inline bool DiagnosticInfo::_internal_has_touchscreen_error() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool DiagnosticInfo::has_touchscreen_error() const {
  return _internal_has_touchscreen_error();
}
inline void DiagnosticInfo::clear_touchscreen_error() {
  touchscreen_error_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000004u;
}
inline const std::string& DiagnosticInfo::touchscreen_error() const {
  // @@protoc_insertion_point(field_get:srv.diagnostic.DiagnosticInfo.touchscreen_error)
  return _internal_touchscreen_error();
}
inline void DiagnosticInfo::set_touchscreen_error(const std::string& value) {
  _internal_set_touchscreen_error(value);
  // @@protoc_insertion_point(field_set:srv.diagnostic.DiagnosticInfo.touchscreen_error)
}
inline std::string* DiagnosticInfo::mutable_touchscreen_error() {
  // @@protoc_insertion_point(field_mutable:srv.diagnostic.DiagnosticInfo.touchscreen_error)
  return _internal_mutable_touchscreen_error();
}
inline const std::string& DiagnosticInfo::_internal_touchscreen_error() const {
  return touchscreen_error_.GetNoArena();
}
inline void DiagnosticInfo::_internal_set_touchscreen_error(const std::string& value) {
  _has_bits_[0] |= 0x00000004u;
  touchscreen_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void DiagnosticInfo::set_touchscreen_error(std::string&& value) {
  _has_bits_[0] |= 0x00000004u;
  touchscreen_error_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:srv.diagnostic.DiagnosticInfo.touchscreen_error)
}
inline void DiagnosticInfo::set_touchscreen_error(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000004u;
  touchscreen_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:srv.diagnostic.DiagnosticInfo.touchscreen_error)
}
inline void DiagnosticInfo::set_touchscreen_error(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000004u;
  touchscreen_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:srv.diagnostic.DiagnosticInfo.touchscreen_error)
}
inline std::string* DiagnosticInfo::_internal_mutable_touchscreen_error() {
  _has_bits_[0] |= 0x00000004u;
  return touchscreen_error_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* DiagnosticInfo::release_touchscreen_error() {
  // @@protoc_insertion_point(field_release:srv.diagnostic.DiagnosticInfo.touchscreen_error)
  if (!_internal_has_touchscreen_error()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000004u;
  return touchscreen_error_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void DiagnosticInfo::set_allocated_touchscreen_error(std::string* touchscreen_error) {
  if (touchscreen_error != nullptr) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  touchscreen_error_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), touchscreen_error);
  // @@protoc_insertion_point(field_set_allocated:srv.diagnostic.DiagnosticInfo.touchscreen_error)
}

// optional string storage_error = 4;
inline bool DiagnosticInfo::_internal_has_storage_error() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool DiagnosticInfo::has_storage_error() const {
  return _internal_has_storage_error();
}
inline void DiagnosticInfo::clear_storage_error() {
  storage_error_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000008u;
}
inline const std::string& DiagnosticInfo::storage_error() const {
  // @@protoc_insertion_point(field_get:srv.diagnostic.DiagnosticInfo.storage_error)
  return _internal_storage_error();
}
inline void DiagnosticInfo::set_storage_error(const std::string& value) {
  _internal_set_storage_error(value);
  // @@protoc_insertion_point(field_set:srv.diagnostic.DiagnosticInfo.storage_error)
}
inline std::string* DiagnosticInfo::mutable_storage_error() {
  // @@protoc_insertion_point(field_mutable:srv.diagnostic.DiagnosticInfo.storage_error)
  return _internal_mutable_storage_error();
}
inline const std::string& DiagnosticInfo::_internal_storage_error() const {
  return storage_error_.GetNoArena();
}
inline void DiagnosticInfo::_internal_set_storage_error(const std::string& value) {
  _has_bits_[0] |= 0x00000008u;
  storage_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void DiagnosticInfo::set_storage_error(std::string&& value) {
  _has_bits_[0] |= 0x00000008u;
  storage_error_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:srv.diagnostic.DiagnosticInfo.storage_error)
}
inline void DiagnosticInfo::set_storage_error(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000008u;
  storage_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:srv.diagnostic.DiagnosticInfo.storage_error)
}
inline void DiagnosticInfo::set_storage_error(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000008u;
  storage_error_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:srv.diagnostic.DiagnosticInfo.storage_error)
}
inline std::string* DiagnosticInfo::_internal_mutable_storage_error() {
  _has_bits_[0] |= 0x00000008u;
  return storage_error_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* DiagnosticInfo::release_storage_error() {
  // @@protoc_insertion_point(field_release:srv.diagnostic.DiagnosticInfo.storage_error)
  if (!_internal_has_storage_error()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000008u;
  return storage_error_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void DiagnosticInfo::set_allocated_storage_error(std::string* storage_error) {
  if (storage_error != nullptr) {
    _has_bits_[0] |= 0x00000008u;
  } else {
    _has_bits_[0] &= ~0x00000008u;
  }
  storage_error_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), storage_error);
  // @@protoc_insertion_point(field_set_allocated:srv.diagnostic.DiagnosticInfo.storage_error)
}

// optional string last_reboot_reason = 5;
inline bool DiagnosticInfo::_internal_has_last_reboot_reason() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool DiagnosticInfo::has_last_reboot_reason() const {
  return _internal_has_last_reboot_reason();
}
inline void DiagnosticInfo::clear_last_reboot_reason() {
  last_reboot_reason_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000010u;
}
inline const std::string& DiagnosticInfo::last_reboot_reason() const {
  // @@protoc_insertion_point(field_get:srv.diagnostic.DiagnosticInfo.last_reboot_reason)
  return _internal_last_reboot_reason();
}
inline void DiagnosticInfo::set_last_reboot_reason(const std::string& value) {
  _internal_set_last_reboot_reason(value);
  // @@protoc_insertion_point(field_set:srv.diagnostic.DiagnosticInfo.last_reboot_reason)
}
inline std::string* DiagnosticInfo::mutable_last_reboot_reason() {
  // @@protoc_insertion_point(field_mutable:srv.diagnostic.DiagnosticInfo.last_reboot_reason)
  return _internal_mutable_last_reboot_reason();
}
inline const std::string& DiagnosticInfo::_internal_last_reboot_reason() const {
  return last_reboot_reason_.GetNoArena();
}
inline void DiagnosticInfo::_internal_set_last_reboot_reason(const std::string& value) {
  _has_bits_[0] |= 0x00000010u;
  last_reboot_reason_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void DiagnosticInfo::set_last_reboot_reason(std::string&& value) {
  _has_bits_[0] |= 0x00000010u;
  last_reboot_reason_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:srv.diagnostic.DiagnosticInfo.last_reboot_reason)
}
inline void DiagnosticInfo::set_last_reboot_reason(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000010u;
  last_reboot_reason_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:srv.diagnostic.DiagnosticInfo.last_reboot_reason)
}
inline void DiagnosticInfo::set_last_reboot_reason(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000010u;
  last_reboot_reason_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:srv.diagnostic.DiagnosticInfo.last_reboot_reason)
}
inline std::string* DiagnosticInfo::_internal_mutable_last_reboot_reason() {
  _has_bits_[0] |= 0x00000010u;
  return last_reboot_reason_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* DiagnosticInfo::release_last_reboot_reason() {
  // @@protoc_insertion_point(field_release:srv.diagnostic.DiagnosticInfo.last_reboot_reason)
  if (!_internal_has_last_reboot_reason()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000010u;
  return last_reboot_reason_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void DiagnosticInfo::set_allocated_last_reboot_reason(std::string* last_reboot_reason) {
  if (last_reboot_reason != nullptr) {
    _has_bits_[0] |= 0x00000010u;
  } else {
    _has_bits_[0] &= ~0x00000010u;
  }
  last_reboot_reason_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), last_reboot_reason);
  // @@protoc_insertion_point(field_set_allocated:srv.diagnostic.DiagnosticInfo.last_reboot_reason)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace diagnostic
}  // namespace srv

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_srv_2fdiagnostic_2eproto
