// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: qrcode/qrcode_event.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_qrcode_2fqrcode_5fevent_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_qrcode_2fqrcode_5fevent_2eproto

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
#include "qrcode/code_raw_data.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_qrcode_2fqrcode_5fevent_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_qrcode_2fqrcode_5fevent_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_qrcode_2fqrcode_5fevent_2eproto;
namespace qrcode {
namespace event {
class QrCodeEvent;
class QrCodeEventDefaultTypeInternal;
extern QrCodeEventDefaultTypeInternal _QrCodeEvent_default_instance_;
}  // namespace event
}  // namespace qrcode
PROTOBUF_NAMESPACE_OPEN
template<> ::qrcode::event::QrCodeEvent* Arena::CreateMaybeMessage<::qrcode::event::QrCodeEvent>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace qrcode {
namespace event {

// ===================================================================

class QrCodeEvent :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:qrcode.event.QrCodeEvent) */ {
 public:
  QrCodeEvent();
  virtual ~QrCodeEvent();

  QrCodeEvent(const QrCodeEvent& from);
  QrCodeEvent(QrCodeEvent&& from) noexcept
    : QrCodeEvent() {
    *this = ::std::move(from);
  }

  inline QrCodeEvent& operator=(const QrCodeEvent& from) {
    CopyFrom(from);
    return *this;
  }
  inline QrCodeEvent& operator=(QrCodeEvent&& from) noexcept {
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
  static const QrCodeEvent& default_instance();

  enum EventCase {
    kRawData = 1,
    EVENT_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const QrCodeEvent* internal_default_instance() {
    return reinterpret_cast<const QrCodeEvent*>(
               &_QrCodeEvent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(QrCodeEvent& a, QrCodeEvent& b) {
    a.Swap(&b);
  }
  inline void Swap(QrCodeEvent* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline QrCodeEvent* New() const final {
    return CreateMaybeMessage<QrCodeEvent>(nullptr);
  }

  QrCodeEvent* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<QrCodeEvent>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const QrCodeEvent& from);
  void MergeFrom(const QrCodeEvent& from);
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
  void InternalSwap(QrCodeEvent* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "qrcode.event.QrCodeEvent";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_qrcode_2fqrcode_5fevent_2eproto);
    return ::descriptor_table_qrcode_2fqrcode_5fevent_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRawDataFieldNumber = 1,
  };
  // optional .qrcode.code_raw_data.RawData raw_data = 1;
  bool has_raw_data() const;
  private:
  bool _internal_has_raw_data() const;
  public:
  void clear_raw_data();
  const ::qrcode::code_raw_data::RawData& raw_data() const;
  ::qrcode::code_raw_data::RawData* release_raw_data();
  ::qrcode::code_raw_data::RawData* mutable_raw_data();
  void set_allocated_raw_data(::qrcode::code_raw_data::RawData* raw_data);
  private:
  const ::qrcode::code_raw_data::RawData& _internal_raw_data() const;
  ::qrcode::code_raw_data::RawData* _internal_mutable_raw_data();
  public:

  void clear_event();
  EventCase event_case() const;
  // @@protoc_insertion_point(class_scope:qrcode.event.QrCodeEvent)
 private:
  class _Internal;
  void set_has_raw_data();

  inline bool has_event() const;
  inline void clear_has_event();

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  union EventUnion {
    EventUnion() {}
    ::qrcode::code_raw_data::RawData* raw_data_;
  } event_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_qrcode_2fqrcode_5fevent_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// QrCodeEvent

// optional .qrcode.code_raw_data.RawData raw_data = 1;
inline bool QrCodeEvent::_internal_has_raw_data() const {
  return event_case() == kRawData;
}
inline bool QrCodeEvent::has_raw_data() const {
  return _internal_has_raw_data();
}
inline void QrCodeEvent::set_has_raw_data() {
  _oneof_case_[0] = kRawData;
}
inline ::qrcode::code_raw_data::RawData* QrCodeEvent::release_raw_data() {
  // @@protoc_insertion_point(field_release:qrcode.event.QrCodeEvent.raw_data)
  if (_internal_has_raw_data()) {
    clear_has_event();
      ::qrcode::code_raw_data::RawData* temp = event_.raw_data_;
    event_.raw_data_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::qrcode::code_raw_data::RawData& QrCodeEvent::_internal_raw_data() const {
  return _internal_has_raw_data()
      ? *event_.raw_data_
      : *reinterpret_cast< ::qrcode::code_raw_data::RawData*>(&::qrcode::code_raw_data::_RawData_default_instance_);
}
inline const ::qrcode::code_raw_data::RawData& QrCodeEvent::raw_data() const {
  // @@protoc_insertion_point(field_get:qrcode.event.QrCodeEvent.raw_data)
  return _internal_raw_data();
}
inline ::qrcode::code_raw_data::RawData* QrCodeEvent::_internal_mutable_raw_data() {
  if (!_internal_has_raw_data()) {
    clear_event();
    set_has_raw_data();
    event_.raw_data_ = CreateMaybeMessage< ::qrcode::code_raw_data::RawData >(
        GetArenaNoVirtual());
  }
  return event_.raw_data_;
}
inline ::qrcode::code_raw_data::RawData* QrCodeEvent::mutable_raw_data() {
  // @@protoc_insertion_point(field_mutable:qrcode.event.QrCodeEvent.raw_data)
  return _internal_mutable_raw_data();
}

inline bool QrCodeEvent::has_event() const {
  return event_case() != EVENT_NOT_SET;
}
inline void QrCodeEvent::clear_has_event() {
  _oneof_case_[0] = EVENT_NOT_SET;
}
inline QrCodeEvent::EventCase QrCodeEvent::event_case() const {
  return QrCodeEvent::EventCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace event
}  // namespace qrcode

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_qrcode_2fqrcode_5fevent_2eproto
