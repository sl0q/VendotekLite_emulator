// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: notification.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_notification_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_notification_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_notification_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_notification_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_notification_2eproto;
namespace common {
namespace notification {
class LogMessage;
class LogMessageDefaultTypeInternal;
extern LogMessageDefaultTypeInternal _LogMessage_default_instance_;
class Notification;
class NotificationDefaultTypeInternal;
extern NotificationDefaultTypeInternal _Notification_default_instance_;
class UserMessage;
class UserMessageDefaultTypeInternal;
extern UserMessageDefaultTypeInternal _UserMessage_default_instance_;
}  // namespace notification
}  // namespace common
PROTOBUF_NAMESPACE_OPEN
template<> ::common::notification::LogMessage* Arena::CreateMaybeMessage<::common::notification::LogMessage>(Arena*);
template<> ::common::notification::Notification* Arena::CreateMaybeMessage<::common::notification::Notification>(Arena*);
template<> ::common::notification::UserMessage* Arena::CreateMaybeMessage<::common::notification::UserMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace common {
namespace notification {

enum LogMessage_Importance : int {
  LogMessage_Importance_EMERGENCY = 1,
  LogMessage_Importance_ALERT = 2,
  LogMessage_Importance_CRITICAL = 3,
  LogMessage_Importance_ERROR = 4,
  LogMessage_Importance_WARNING = 5,
  LogMessage_Importance_NOTICE = 6,
  LogMessage_Importance_INFO = 7,
  LogMessage_Importance_DEBUG = 8
};
bool LogMessage_Importance_IsValid(int value);
constexpr LogMessage_Importance LogMessage_Importance_Importance_MIN = LogMessage_Importance_EMERGENCY;
constexpr LogMessage_Importance LogMessage_Importance_Importance_MAX = LogMessage_Importance_DEBUG;
constexpr int LogMessage_Importance_Importance_ARRAYSIZE = LogMessage_Importance_Importance_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* LogMessage_Importance_descriptor();
template<typename T>
inline const std::string& LogMessage_Importance_Name(T enum_t_value) {
  static_assert(::std::is_same<T, LogMessage_Importance>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function LogMessage_Importance_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    LogMessage_Importance_descriptor(), enum_t_value);
}
inline bool LogMessage_Importance_Parse(
    const std::string& name, LogMessage_Importance* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<LogMessage_Importance>(
    LogMessage_Importance_descriptor(), name, value);
}
enum UserMessage_MessageId : int {
  UserMessage_MessageId_PRESENT_ONE_CARD_ONLY = 0
};
bool UserMessage_MessageId_IsValid(int value);
constexpr UserMessage_MessageId UserMessage_MessageId_MessageId_MIN = UserMessage_MessageId_PRESENT_ONE_CARD_ONLY;
constexpr UserMessage_MessageId UserMessage_MessageId_MessageId_MAX = UserMessage_MessageId_PRESENT_ONE_CARD_ONLY;
constexpr int UserMessage_MessageId_MessageId_ARRAYSIZE = UserMessage_MessageId_MessageId_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* UserMessage_MessageId_descriptor();
template<typename T>
inline const std::string& UserMessage_MessageId_Name(T enum_t_value) {
  static_assert(::std::is_same<T, UserMessage_MessageId>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function UserMessage_MessageId_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    UserMessage_MessageId_descriptor(), enum_t_value);
}
inline bool UserMessage_MessageId_Parse(
    const std::string& name, UserMessage_MessageId* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<UserMessage_MessageId>(
    UserMessage_MessageId_descriptor(), name, value);
}
// ===================================================================

class Notification :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:common.notification.Notification) */ {
 public:
  Notification();
  virtual ~Notification();

  Notification(const Notification& from);
  Notification(Notification&& from) noexcept
    : Notification() {
    *this = ::std::move(from);
  }

  inline Notification& operator=(const Notification& from) {
    CopyFrom(from);
    return *this;
  }
  inline Notification& operator=(Notification&& from) noexcept {
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
  static const Notification& default_instance();

  enum NotificationCase {
    kLogMessage = 1,
    kUserMessage = 2,
    NOTIFICATION_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Notification* internal_default_instance() {
    return reinterpret_cast<const Notification*>(
               &_Notification_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Notification& a, Notification& b) {
    a.Swap(&b);
  }
  inline void Swap(Notification* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Notification* New() const final {
    return CreateMaybeMessage<Notification>(nullptr);
  }

  Notification* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Notification>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Notification& from);
  void MergeFrom(const Notification& from);
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
  void InternalSwap(Notification* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "common.notification.Notification";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_notification_2eproto);
    return ::descriptor_table_notification_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLogMessageFieldNumber = 1,
    kUserMessageFieldNumber = 2,
  };
  // optional .common.notification.LogMessage log_message = 1;
  bool has_log_message() const;
  private:
  bool _internal_has_log_message() const;
  public:
  void clear_log_message();
  const ::common::notification::LogMessage& log_message() const;
  ::common::notification::LogMessage* release_log_message();
  ::common::notification::LogMessage* mutable_log_message();
  void set_allocated_log_message(::common::notification::LogMessage* log_message);
  private:
  const ::common::notification::LogMessage& _internal_log_message() const;
  ::common::notification::LogMessage* _internal_mutable_log_message();
  public:

  // optional .common.notification.UserMessage user_message = 2;
  bool has_user_message() const;
  private:
  bool _internal_has_user_message() const;
  public:
  void clear_user_message();
  const ::common::notification::UserMessage& user_message() const;
  ::common::notification::UserMessage* release_user_message();
  ::common::notification::UserMessage* mutable_user_message();
  void set_allocated_user_message(::common::notification::UserMessage* user_message);
  private:
  const ::common::notification::UserMessage& _internal_user_message() const;
  ::common::notification::UserMessage* _internal_mutable_user_message();
  public:

  void clear_notification();
  NotificationCase notification_case() const;
  // @@protoc_insertion_point(class_scope:common.notification.Notification)
 private:
  class _Internal;
  void set_has_log_message();
  void set_has_user_message();

  inline bool has_notification() const;
  inline void clear_has_notification();

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  union NotificationUnion {
    NotificationUnion() {}
    ::common::notification::LogMessage* log_message_;
    ::common::notification::UserMessage* user_message_;
  } notification_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_notification_2eproto;
};
// -------------------------------------------------------------------

class LogMessage :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:common.notification.LogMessage) */ {
 public:
  LogMessage();
  virtual ~LogMessage();

  LogMessage(const LogMessage& from);
  LogMessage(LogMessage&& from) noexcept
    : LogMessage() {
    *this = ::std::move(from);
  }

  inline LogMessage& operator=(const LogMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline LogMessage& operator=(LogMessage&& from) noexcept {
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
  static const LogMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LogMessage* internal_default_instance() {
    return reinterpret_cast<const LogMessage*>(
               &_LogMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(LogMessage& a, LogMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(LogMessage* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline LogMessage* New() const final {
    return CreateMaybeMessage<LogMessage>(nullptr);
  }

  LogMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<LogMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const LogMessage& from);
  void MergeFrom(const LogMessage& from);
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
  void InternalSwap(LogMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "common.notification.LogMessage";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_notification_2eproto);
    return ::descriptor_table_notification_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef LogMessage_Importance Importance;
  static constexpr Importance EMERGENCY =
    LogMessage_Importance_EMERGENCY;
  static constexpr Importance ALERT =
    LogMessage_Importance_ALERT;
  static constexpr Importance CRITICAL =
    LogMessage_Importance_CRITICAL;
  static constexpr Importance ERROR =
    LogMessage_Importance_ERROR;
  static constexpr Importance WARNING =
    LogMessage_Importance_WARNING;
  static constexpr Importance NOTICE =
    LogMessage_Importance_NOTICE;
  static constexpr Importance INFO =
    LogMessage_Importance_INFO;
  static constexpr Importance DEBUG =
    LogMessage_Importance_DEBUG;
  static inline bool Importance_IsValid(int value) {
    return LogMessage_Importance_IsValid(value);
  }
  static constexpr Importance Importance_MIN =
    LogMessage_Importance_Importance_MIN;
  static constexpr Importance Importance_MAX =
    LogMessage_Importance_Importance_MAX;
  static constexpr int Importance_ARRAYSIZE =
    LogMessage_Importance_Importance_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Importance_descriptor() {
    return LogMessage_Importance_descriptor();
  }
  template<typename T>
  static inline const std::string& Importance_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Importance>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Importance_Name.");
    return LogMessage_Importance_Name(enum_t_value);
  }
  static inline bool Importance_Parse(const std::string& name,
      Importance* value) {
    return LogMessage_Importance_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kMsgFieldNumber = 2,
    kLevelFieldNumber = 1,
  };
  // required string msg = 2;
  bool has_msg() const;
  private:
  bool _internal_has_msg() const;
  public:
  void clear_msg();
  const std::string& msg() const;
  void set_msg(const std::string& value);
  void set_msg(std::string&& value);
  void set_msg(const char* value);
  void set_msg(const char* value, size_t size);
  std::string* mutable_msg();
  std::string* release_msg();
  void set_allocated_msg(std::string* msg);
  private:
  const std::string& _internal_msg() const;
  void _internal_set_msg(const std::string& value);
  std::string* _internal_mutable_msg();
  public:

  // required .common.notification.LogMessage.Importance level = 1;
  bool has_level() const;
  private:
  bool _internal_has_level() const;
  public:
  void clear_level();
  ::common::notification::LogMessage_Importance level() const;
  void set_level(::common::notification::LogMessage_Importance value);
  private:
  ::common::notification::LogMessage_Importance _internal_level() const;
  void _internal_set_level(::common::notification::LogMessage_Importance value);
  public:

  // @@protoc_insertion_point(class_scope:common.notification.LogMessage)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  int level_;
  friend struct ::TableStruct_notification_2eproto;
};
// -------------------------------------------------------------------

class UserMessage :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:common.notification.UserMessage) */ {
 public:
  UserMessage();
  virtual ~UserMessage();

  UserMessage(const UserMessage& from);
  UserMessage(UserMessage&& from) noexcept
    : UserMessage() {
    *this = ::std::move(from);
  }

  inline UserMessage& operator=(const UserMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline UserMessage& operator=(UserMessage&& from) noexcept {
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
  static const UserMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const UserMessage* internal_default_instance() {
    return reinterpret_cast<const UserMessage*>(
               &_UserMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(UserMessage& a, UserMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(UserMessage* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline UserMessage* New() const final {
    return CreateMaybeMessage<UserMessage>(nullptr);
  }

  UserMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<UserMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const UserMessage& from);
  void MergeFrom(const UserMessage& from);
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
  void InternalSwap(UserMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "common.notification.UserMessage";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_notification_2eproto);
    return ::descriptor_table_notification_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef UserMessage_MessageId MessageId;
  static constexpr MessageId PRESENT_ONE_CARD_ONLY =
    UserMessage_MessageId_PRESENT_ONE_CARD_ONLY;
  static inline bool MessageId_IsValid(int value) {
    return UserMessage_MessageId_IsValid(value);
  }
  static constexpr MessageId MessageId_MIN =
    UserMessage_MessageId_MessageId_MIN;
  static constexpr MessageId MessageId_MAX =
    UserMessage_MessageId_MessageId_MAX;
  static constexpr int MessageId_ARRAYSIZE =
    UserMessage_MessageId_MessageId_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  MessageId_descriptor() {
    return UserMessage_MessageId_descriptor();
  }
  template<typename T>
  static inline const std::string& MessageId_Name(T enum_t_value) {
    static_assert(::std::is_same<T, MessageId>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function MessageId_Name.");
    return UserMessage_MessageId_Name(enum_t_value);
  }
  static inline bool MessageId_Parse(const std::string& name,
      MessageId* value) {
    return UserMessage_MessageId_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kMessageIdFieldNumber = 1,
  };
  // required .common.notification.UserMessage.MessageId message_id = 1;
  bool has_message_id() const;
  private:
  bool _internal_has_message_id() const;
  public:
  void clear_message_id();
  ::common::notification::UserMessage_MessageId message_id() const;
  void set_message_id(::common::notification::UserMessage_MessageId value);
  private:
  ::common::notification::UserMessage_MessageId _internal_message_id() const;
  void _internal_set_message_id(::common::notification::UserMessage_MessageId value);
  public:

  // @@protoc_insertion_point(class_scope:common.notification.UserMessage)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  int message_id_;
  friend struct ::TableStruct_notification_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Notification

// optional .common.notification.LogMessage log_message = 1;
inline bool Notification::_internal_has_log_message() const {
  return notification_case() == kLogMessage;
}
inline bool Notification::has_log_message() const {
  return _internal_has_log_message();
}
inline void Notification::set_has_log_message() {
  _oneof_case_[0] = kLogMessage;
}
inline void Notification::clear_log_message() {
  if (_internal_has_log_message()) {
    delete notification_.log_message_;
    clear_has_notification();
  }
}
inline ::common::notification::LogMessage* Notification::release_log_message() {
  // @@protoc_insertion_point(field_release:common.notification.Notification.log_message)
  if (_internal_has_log_message()) {
    clear_has_notification();
      ::common::notification::LogMessage* temp = notification_.log_message_;
    notification_.log_message_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::common::notification::LogMessage& Notification::_internal_log_message() const {
  return _internal_has_log_message()
      ? *notification_.log_message_
      : *reinterpret_cast< ::common::notification::LogMessage*>(&::common::notification::_LogMessage_default_instance_);
}
inline const ::common::notification::LogMessage& Notification::log_message() const {
  // @@protoc_insertion_point(field_get:common.notification.Notification.log_message)
  return _internal_log_message();
}
inline ::common::notification::LogMessage* Notification::_internal_mutable_log_message() {
  if (!_internal_has_log_message()) {
    clear_notification();
    set_has_log_message();
    notification_.log_message_ = CreateMaybeMessage< ::common::notification::LogMessage >(
        GetArenaNoVirtual());
  }
  return notification_.log_message_;
}
inline ::common::notification::LogMessage* Notification::mutable_log_message() {
  // @@protoc_insertion_point(field_mutable:common.notification.Notification.log_message)
  return _internal_mutable_log_message();
}

// optional .common.notification.UserMessage user_message = 2;
inline bool Notification::_internal_has_user_message() const {
  return notification_case() == kUserMessage;
}
inline bool Notification::has_user_message() const {
  return _internal_has_user_message();
}
inline void Notification::set_has_user_message() {
  _oneof_case_[0] = kUserMessage;
}
inline void Notification::clear_user_message() {
  if (_internal_has_user_message()) {
    delete notification_.user_message_;
    clear_has_notification();
  }
}
inline ::common::notification::UserMessage* Notification::release_user_message() {
  // @@protoc_insertion_point(field_release:common.notification.Notification.user_message)
  if (_internal_has_user_message()) {
    clear_has_notification();
      ::common::notification::UserMessage* temp = notification_.user_message_;
    notification_.user_message_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::common::notification::UserMessage& Notification::_internal_user_message() const {
  return _internal_has_user_message()
      ? *notification_.user_message_
      : *reinterpret_cast< ::common::notification::UserMessage*>(&::common::notification::_UserMessage_default_instance_);
}
inline const ::common::notification::UserMessage& Notification::user_message() const {
  // @@protoc_insertion_point(field_get:common.notification.Notification.user_message)
  return _internal_user_message();
}
inline ::common::notification::UserMessage* Notification::_internal_mutable_user_message() {
  if (!_internal_has_user_message()) {
    clear_notification();
    set_has_user_message();
    notification_.user_message_ = CreateMaybeMessage< ::common::notification::UserMessage >(
        GetArenaNoVirtual());
  }
  return notification_.user_message_;
}
inline ::common::notification::UserMessage* Notification::mutable_user_message() {
  // @@protoc_insertion_point(field_mutable:common.notification.Notification.user_message)
  return _internal_mutable_user_message();
}

inline bool Notification::has_notification() const {
  return notification_case() != NOTIFICATION_NOT_SET;
}
inline void Notification::clear_has_notification() {
  _oneof_case_[0] = NOTIFICATION_NOT_SET;
}
inline Notification::NotificationCase Notification::notification_case() const {
  return Notification::NotificationCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// LogMessage

// required .common.notification.LogMessage.Importance level = 1;
inline bool LogMessage::_internal_has_level() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool LogMessage::has_level() const {
  return _internal_has_level();
}
inline void LogMessage::clear_level() {
  level_ = 1;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::common::notification::LogMessage_Importance LogMessage::_internal_level() const {
  return static_cast< ::common::notification::LogMessage_Importance >(level_);
}
inline ::common::notification::LogMessage_Importance LogMessage::level() const {
  // @@protoc_insertion_point(field_get:common.notification.LogMessage.level)
  return _internal_level();
}
inline void LogMessage::_internal_set_level(::common::notification::LogMessage_Importance value) {
  assert(::common::notification::LogMessage_Importance_IsValid(value));
  _has_bits_[0] |= 0x00000002u;
  level_ = value;
}
inline void LogMessage::set_level(::common::notification::LogMessage_Importance value) {
  _internal_set_level(value);
  // @@protoc_insertion_point(field_set:common.notification.LogMessage.level)
}

// required string msg = 2;
inline bool LogMessage::_internal_has_msg() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool LogMessage::has_msg() const {
  return _internal_has_msg();
}
inline void LogMessage::clear_msg() {
  msg_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& LogMessage::msg() const {
  // @@protoc_insertion_point(field_get:common.notification.LogMessage.msg)
  return _internal_msg();
}
inline void LogMessage::set_msg(const std::string& value) {
  _internal_set_msg(value);
  // @@protoc_insertion_point(field_set:common.notification.LogMessage.msg)
}
inline std::string* LogMessage::mutable_msg() {
  // @@protoc_insertion_point(field_mutable:common.notification.LogMessage.msg)
  return _internal_mutable_msg();
}
inline const std::string& LogMessage::_internal_msg() const {
  return msg_.GetNoArena();
}
inline void LogMessage::_internal_set_msg(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void LogMessage::set_msg(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  msg_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:common.notification.LogMessage.msg)
}
inline void LogMessage::set_msg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:common.notification.LogMessage.msg)
}
inline void LogMessage::set_msg(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:common.notification.LogMessage.msg)
}
inline std::string* LogMessage::_internal_mutable_msg() {
  _has_bits_[0] |= 0x00000001u;
  return msg_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* LogMessage::release_msg() {
  // @@protoc_insertion_point(field_release:common.notification.LogMessage.msg)
  if (!_internal_has_msg()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return msg_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void LogMessage::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  msg_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:common.notification.LogMessage.msg)
}

// -------------------------------------------------------------------

// UserMessage

// required .common.notification.UserMessage.MessageId message_id = 1;
inline bool UserMessage::_internal_has_message_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool UserMessage::has_message_id() const {
  return _internal_has_message_id();
}
inline void UserMessage::clear_message_id() {
  message_id_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::common::notification::UserMessage_MessageId UserMessage::_internal_message_id() const {
  return static_cast< ::common::notification::UserMessage_MessageId >(message_id_);
}
inline ::common::notification::UserMessage_MessageId UserMessage::message_id() const {
  // @@protoc_insertion_point(field_get:common.notification.UserMessage.message_id)
  return _internal_message_id();
}
inline void UserMessage::_internal_set_message_id(::common::notification::UserMessage_MessageId value) {
  assert(::common::notification::UserMessage_MessageId_IsValid(value));
  _has_bits_[0] |= 0x00000001u;
  message_id_ = value;
}
inline void UserMessage::set_message_id(::common::notification::UserMessage_MessageId value) {
  _internal_set_message_id(value);
  // @@protoc_insertion_point(field_set:common.notification.UserMessage.message_id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace notification
}  // namespace common

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::common::notification::LogMessage_Importance> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::common::notification::LogMessage_Importance>() {
  return ::common::notification::LogMessage_Importance_descriptor();
}
template <> struct is_proto_enum< ::common::notification::UserMessage_MessageId> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::common::notification::UserMessage_MessageId>() {
  return ::common::notification::UserMessage_MessageId_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_notification_2eproto
