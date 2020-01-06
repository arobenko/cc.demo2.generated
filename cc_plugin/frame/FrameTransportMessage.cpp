// Generated by commsdsl2comms v3.3.0

#include "FrameTransportMessage.h"

#include "comms_champion/property/field.h"
#include "cc_plugin/field/MsgId.h"

namespace cc = comms_champion;

namespace demo2
{

namespace cc_plugin
{

namespace frame
{

namespace
{

struct SyncLayer
{
    static QVariantMap createProps_sync()
    {
        using Field = demo2::frame::FrameLayers<>::SyncMembers::Sync;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

struct SizeLayer
{
    static QVariantMap createProps_size()
    {
        using Field = demo2::frame::FrameLayers<>::SizeMembers::Size;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .displayOffset(2)
                .asMap();
        
    }
    
};

struct IdLayer
{
    static QVariantMap createProps_msgId()
    {
        return cc_plugin::field::createProps_msgId("MsgId");
    }
    
};

struct VersionLayer
{
    static QVariantMap createProps_version()
    {
        using Field = demo2::frame::FrameLayers<>::VersionMembers::Version;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};

struct DataLayer
{
    static QVariantMap createProps_data()
    {
        return cc::property::field::ArrayList().name("Data").asMap();
    }
    
};

struct ChecksumLayer
{
    static QVariantMap createProps_checksum()
    {
        using Field = demo2::frame::FrameLayers<>::ChecksumMembers::Checksum;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .asMap();
        
    }
    
};


QVariantList createProps()
{
     QVariantList props;
     props.append(SyncLayer::createProps_sync());
     props.append(SizeLayer::createProps_size());
     props.append(IdLayer::createProps_msgId());
     props.append(VersionLayer::createProps_version());
     props.append(DataLayer::createProps_data());
     props.append(ChecksumLayer::createProps_checksum());
     return props;
}

} // namespace

const QVariantList& FrameTransportMessage::fieldsPropertiesImpl() const
{
    static const QVariantList Props = createProps();
    return Props;
}

comms::ErrorStatus FrameTransportMessage::readImpl(ReadIterator& iter, std::size_t len)
{
    len -= 2U;
    auto es = doReadUntilAndUpdateLen<5U>(iter, len);
    if (es == comms::ErrorStatus::Success) {
        len += 2U;
        es = doReadFrom<5U>(iter, len);
    }

    return es;
}

} // namespace frame

} // namespace cc_plugin

} // namespace demo2


