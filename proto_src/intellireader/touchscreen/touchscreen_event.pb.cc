// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: touchscreen/touchscreen_event.proto

#include "touchscreen/touchscreen_event.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_touchscreen_2fcoordinates_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Coordinates_touchscreen_2fcoordinates_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_touchscreen_2fwidget_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_WidgetId_touchscreen_2fwidget_2eproto;
namespace touchscreen {
namespace event {
class TouchscreenEventDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TouchscreenEvent> _instance;
  const ::touchscreen::widget::WidgetId* widget_id_;
  const ::touchscreen::coordinates::Coordinates* coordinates_;
} _TouchscreenEvent_default_instance_;
}  // namespace event
}  // namespace touchscreen
static void InitDefaultsscc_info_TouchscreenEvent_touchscreen_2ftouchscreen_5fevent_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::touchscreen::event::_TouchscreenEvent_default_instance_;
    new (ptr) ::touchscreen::event::TouchscreenEvent();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::touchscreen::event::TouchscreenEvent::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_TouchscreenEvent_touchscreen_2ftouchscreen_5fevent_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_TouchscreenEvent_touchscreen_2ftouchscreen_5fevent_2eproto}, {
      &scc_info_WidgetId_touchscreen_2fwidget_2eproto.base,
      &scc_info_Coordinates_touchscreen_2fcoordinates_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_touchscreen_2ftouchscreen_5fevent_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_touchscreen_2ftouchscreen_5fevent_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_touchscreen_2ftouchscreen_5fevent_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_touchscreen_2ftouchscreen_5fevent_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::touchscreen::event::TouchscreenEvent, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::touchscreen::event::TouchscreenEvent, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::touchscreen::event::TouchscreenEvent, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  offsetof(::touchscreen::event::TouchscreenEventDefaultTypeInternal, widget_id_),
  offsetof(::touchscreen::event::TouchscreenEventDefaultTypeInternal, coordinates_),
  PROTOBUF_FIELD_OFFSET(::touchscreen::event::TouchscreenEvent, event_),
  ~0u,
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::touchscreen::event::TouchscreenEvent)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::touchscreen::event::_TouchscreenEvent_default_instance_),
};

const char descriptor_table_protodef_touchscreen_2ftouchscreen_5fevent_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n#touchscreen/touchscreen_event.proto\022\021t"
  "ouchscreen.event\032\035touchscreen/coordinate"
  "s.proto\032\030touchscreen/widget.proto\"\213\001\n\020To"
  "uchscreenEvent\0221\n\twidget_id\030\001 \001(\0132\034.touc"
  "hscreen.widget.WidgetIdH\000\022;\n\013coordinates"
  "\030\002 \001(\0132$.touchscreen.coordinates.Coordin"
  "atesH\000B\007\n\005event"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto_deps[2] = {
  &::descriptor_table_touchscreen_2fcoordinates_2eproto,
  &::descriptor_table_touchscreen_2fwidget_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto_sccs[1] = {
  &scc_info_TouchscreenEvent_touchscreen_2ftouchscreen_5fevent_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto_once;
static bool descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto = {
  &descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto_initialized, descriptor_table_protodef_touchscreen_2ftouchscreen_5fevent_2eproto, "touchscreen/touchscreen_event.proto", 255,
  &descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto_once, descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto_sccs, descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_touchscreen_2ftouchscreen_5fevent_2eproto::offsets,
  file_level_metadata_touchscreen_2ftouchscreen_5fevent_2eproto, 1, file_level_enum_descriptors_touchscreen_2ftouchscreen_5fevent_2eproto, file_level_service_descriptors_touchscreen_2ftouchscreen_5fevent_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_touchscreen_2ftouchscreen_5fevent_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_touchscreen_2ftouchscreen_5fevent_2eproto), true);
namespace touchscreen {
namespace event {

// ===================================================================

void TouchscreenEvent::InitAsDefaultInstance() {
  ::touchscreen::event::_TouchscreenEvent_default_instance_.widget_id_ = const_cast< ::touchscreen::widget::WidgetId*>(
      ::touchscreen::widget::WidgetId::internal_default_instance());
  ::touchscreen::event::_TouchscreenEvent_default_instance_.coordinates_ = const_cast< ::touchscreen::coordinates::Coordinates*>(
      ::touchscreen::coordinates::Coordinates::internal_default_instance());
}
class TouchscreenEvent::_Internal {
 public:
  using HasBits = decltype(std::declval<TouchscreenEvent>()._has_bits_);
  static const ::touchscreen::widget::WidgetId& widget_id(const TouchscreenEvent* msg);
  static const ::touchscreen::coordinates::Coordinates& coordinates(const TouchscreenEvent* msg);
};

const ::touchscreen::widget::WidgetId&
TouchscreenEvent::_Internal::widget_id(const TouchscreenEvent* msg) {
  return *msg->event_.widget_id_;
}
const ::touchscreen::coordinates::Coordinates&
TouchscreenEvent::_Internal::coordinates(const TouchscreenEvent* msg) {
  return *msg->event_.coordinates_;
}
void TouchscreenEvent::set_allocated_widget_id(::touchscreen::widget::WidgetId* widget_id) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  clear_event();
  if (widget_id) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      widget_id = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, widget_id, submessage_arena);
    }
    set_has_widget_id();
    event_.widget_id_ = widget_id;
  }
  // @@protoc_insertion_point(field_set_allocated:touchscreen.event.TouchscreenEvent.widget_id)
}
void TouchscreenEvent::clear_widget_id() {
  if (_internal_has_widget_id()) {
    delete event_.widget_id_;
    clear_has_event();
  }
}
void TouchscreenEvent::set_allocated_coordinates(::touchscreen::coordinates::Coordinates* coordinates) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  clear_event();
  if (coordinates) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      coordinates = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, coordinates, submessage_arena);
    }
    set_has_coordinates();
    event_.coordinates_ = coordinates;
  }
  // @@protoc_insertion_point(field_set_allocated:touchscreen.event.TouchscreenEvent.coordinates)
}
void TouchscreenEvent::clear_coordinates() {
  if (_internal_has_coordinates()) {
    delete event_.coordinates_;
    clear_has_event();
  }
}
TouchscreenEvent::TouchscreenEvent()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:touchscreen.event.TouchscreenEvent)
}
TouchscreenEvent::TouchscreenEvent(const TouchscreenEvent& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  clear_has_event();
  switch (from.event_case()) {
    case kWidgetId: {
      _internal_mutable_widget_id()->::touchscreen::widget::WidgetId::MergeFrom(from._internal_widget_id());
      break;
    }
    case kCoordinates: {
      _internal_mutable_coordinates()->::touchscreen::coordinates::Coordinates::MergeFrom(from._internal_coordinates());
      break;
    }
    case EVENT_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:touchscreen.event.TouchscreenEvent)
}

void TouchscreenEvent::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_TouchscreenEvent_touchscreen_2ftouchscreen_5fevent_2eproto.base);
  clear_has_event();
}

TouchscreenEvent::~TouchscreenEvent() {
  // @@protoc_insertion_point(destructor:touchscreen.event.TouchscreenEvent)
  SharedDtor();
}

void TouchscreenEvent::SharedDtor() {
  if (has_event()) {
    clear_event();
  }
}

void TouchscreenEvent::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TouchscreenEvent& TouchscreenEvent::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TouchscreenEvent_touchscreen_2ftouchscreen_5fevent_2eproto.base);
  return *internal_default_instance();
}


void TouchscreenEvent::clear_event() {
// @@protoc_insertion_point(one_of_clear_start:touchscreen.event.TouchscreenEvent)
  switch (event_case()) {
    case kWidgetId: {
      delete event_.widget_id_;
      break;
    }
    case kCoordinates: {
      delete event_.coordinates_;
      break;
    }
    case EVENT_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = EVENT_NOT_SET;
}


void TouchscreenEvent::Clear() {
// @@protoc_insertion_point(message_clear_start:touchscreen.event.TouchscreenEvent)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clear_event();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* TouchscreenEvent::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional .touchscreen.widget.WidgetId widget_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_widget_id(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .touchscreen.coordinates.Coordinates coordinates = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_coordinates(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* TouchscreenEvent::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:touchscreen.event.TouchscreenEvent)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  switch (event_case()) {
    case kWidgetId: {
      target = stream->EnsureSpace(target);
      target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(
          1, _Internal::widget_id(this), target, stream);
      break;
    }
    case kCoordinates: {
      target = stream->EnsureSpace(target);
      target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(
          2, _Internal::coordinates(this), target, stream);
      break;
    }
    default: ;
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:touchscreen.event.TouchscreenEvent)
  return target;
}

size_t TouchscreenEvent::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:touchscreen.event.TouchscreenEvent)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  switch (event_case()) {
    // optional .touchscreen.widget.WidgetId widget_id = 1;
    case kWidgetId: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *event_.widget_id_);
      break;
    }
    // optional .touchscreen.coordinates.Coordinates coordinates = 2;
    case kCoordinates: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *event_.coordinates_);
      break;
    }
    case EVENT_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TouchscreenEvent::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:touchscreen.event.TouchscreenEvent)
  GOOGLE_DCHECK_NE(&from, this);
  const TouchscreenEvent* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<TouchscreenEvent>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:touchscreen.event.TouchscreenEvent)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:touchscreen.event.TouchscreenEvent)
    MergeFrom(*source);
  }
}

void TouchscreenEvent::MergeFrom(const TouchscreenEvent& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:touchscreen.event.TouchscreenEvent)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  switch (from.event_case()) {
    case kWidgetId: {
      _internal_mutable_widget_id()->::touchscreen::widget::WidgetId::MergeFrom(from._internal_widget_id());
      break;
    }
    case kCoordinates: {
      _internal_mutable_coordinates()->::touchscreen::coordinates::Coordinates::MergeFrom(from._internal_coordinates());
      break;
    }
    case EVENT_NOT_SET: {
      break;
    }
  }
}

void TouchscreenEvent::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:touchscreen.event.TouchscreenEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TouchscreenEvent::CopyFrom(const TouchscreenEvent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:touchscreen.event.TouchscreenEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TouchscreenEvent::IsInitialized() const {
  switch (event_case()) {
    case kWidgetId: {
      if (has_widget_id()) {
        if (!this->widget_id().IsInitialized()) return false;
      }
      break;
    }
    case kCoordinates: {
      if (has_coordinates()) {
        if (!this->coordinates().IsInitialized()) return false;
      }
      break;
    }
    case EVENT_NOT_SET: {
      break;
    }
  }
  return true;
}

void TouchscreenEvent::InternalSwap(TouchscreenEvent* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(event_, other->event_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata TouchscreenEvent::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace event
}  // namespace touchscreen
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::touchscreen::event::TouchscreenEvent* Arena::CreateMaybeMessage< ::touchscreen::event::TouchscreenEvent >(Arena* arena) {
  return Arena::CreateInternal< ::touchscreen::event::TouchscreenEvent >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
