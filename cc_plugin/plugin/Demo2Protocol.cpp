#include "Demo2Protocol.h"

#include <cassert>
#include "comms_champion/ProtocolBase.h"
#include "cc_plugin/frame/Frame.h"
#include "cc_plugin/frame/FrameTransportMessage.h"

namespace cc = comms_champion;

namespace demo2
{

namespace cc_plugin
{

namespace plugin
{

class Demo2ProtocolImpl : public
    cc::ProtocolBase<
        demo2::cc_plugin::frame::Frame,
        demo2::cc_plugin::frame::FrameTransportMessage
    >
{
    using Base =
        cc::ProtocolBase<
            demo2::cc_plugin::frame::Frame,
            demo2::cc_plugin::frame::FrameTransportMessage
        >;
public:
    friend class demo2::cc_plugin::plugin::Demo2Protocol;

    Demo2ProtocolImpl() = default;
    virtual ~Demo2ProtocolImpl() = default;

    int getVersion() const
    {
        return m_version;
    }
    
    void setVersion(int value)
    {
        m_version = value;
    }
    
protected:
    virtual const QString& nameImpl() const override
    {
        static const QString Str("demo2");
        return Str;
    }

    virtual MessagesList createAllMessagesImpl() override
    {
        auto list = Base::createAllMessagesImpl();
        for (auto& mPtr : list) {
            updateMessageWithVersion(*mPtr);
        }
        return list;
    }
    
    virtual cc::MessagePtr createMessageImpl(const QString& idAsString, unsigned idx) override
    {
        auto mPtr = Base::createMessageImpl(idAsString, idx);
        updateMessageWithVersion(*mPtr);
        return mPtr;
    }
    
    
    using Base::createInvalidMessageImpl;
    using Base::createRawDataMessageImpl;
    using Base::createExtraInfoMessageImpl;

private:
    void updateMessageWithVersion(cc::Message& msg)
    {
        assert(dynamic_cast<demo2::cc_plugin::Message*>(&msg) != nullptr);
        static_assert(demo2::cc_plugin::Message::hasVersionInTransportFields(),
            "Interface type is expected to has version in transport fields");
        static const std::size_t VersionIdx = 
            demo2::cc_plugin::Message::InterfaceOptions::VersionInExtraTransportFields;
        auto& castedMsg = static_cast<demo2::cc_plugin::Message&>(msg);
        std::get<VersionIdx>(castedMsg.transportFields()).value() =
            static_cast<demo2::cc_plugin::Message::VersionType>(m_version);
        castedMsg.refresh();
        updateMessage(msg);
    }

    int m_version = 5U;

};

Demo2Protocol::Demo2Protocol()
  : m_pImpl(new Demo2ProtocolImpl())
{
}

Demo2Protocol::~Demo2Protocol() = default;

int Demo2Protocol::getVersion() const
{
    return m_pImpl->getVersion();
}

void Demo2Protocol::setVersion(int value)
{
    m_pImpl->setVersion(value);
}

const QString& Demo2Protocol::nameImpl() const
{
    return m_pImpl->name();
}

Demo2Protocol::MessagesList Demo2Protocol::readImpl(const cc::DataInfo& dataInfo, bool final)
{
    return m_pImpl->read(dataInfo, final);
}

cc::DataInfoPtr Demo2Protocol::writeImpl(cc::Message& msg)
{
    return m_pImpl->write(msg);
}

Demo2Protocol::MessagesList Demo2Protocol::createAllMessagesImpl()
{
    return m_pImpl->createAllMessages();
}

cc::MessagePtr Demo2Protocol::createMessageImpl(const QString& idAsString, unsigned idx)
{
    return static_cast<cc::Protocol*>(m_pImpl.get())->createMessage(idAsString, idx);
}

Demo2Protocol::UpdateStatus Demo2Protocol::updateMessageImpl(cc::Message& msg)
{
    return m_pImpl->updateMessage(msg);
}

cc::MessagePtr Demo2Protocol::cloneMessageImpl(const cc::Message& msg)
{
    return m_pImpl->cloneMessage(msg);
}

cc::MessagePtr Demo2Protocol::createInvalidMessageImpl()
{
    return m_pImpl->createInvalidMessageImpl();
}

cc::MessagePtr Demo2Protocol::createRawDataMessageImpl()
{
    return m_pImpl->createRawDataMessageImpl();
}

cc::MessagePtr Demo2Protocol::createExtraInfoMessageImpl()
{
    return m_pImpl->createExtraInfoMessageImpl();
}

} // namespace plugin

} // namespace cc_plugin

} // namespace demo2


