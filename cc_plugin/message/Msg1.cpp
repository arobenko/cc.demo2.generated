// Generated by commsdsl2comms v3.3.1

#include "Msg1.h"

#include "comms_champion/property/field.h"
namespace cc = comms_champion;

namespace demo2
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_f1()
{
    using Field = demo2::message::Msg1Fields<>::F1;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_f2()
{
    using InnerField = demo2::message::Msg1Fields<>::F2Field;
    auto props =
        cc::property::field::ForField<InnerField>()
            .name(InnerField::name())
            .asMap();
    
    using Field = demo2::message::Msg1Fields<>::F2;
    return
        cc::property::field::ForField<Field>()
            .name(InnerField::name())
            .uncheckable()
            .field(std::move(props))
            .asMap();
    
}

static QVariantMap createProps_f3()
{
    using InnerField = demo2::message::Msg1Fields<>::F3Field;
    auto props =
        cc::property::field::ForField<InnerField>()
            .name(InnerField::name())
            .asMap();
    
    using Field = demo2::message::Msg1Fields<>::F3;
    return
        cc::property::field::ForField<Field>()
            .name(InnerField::name())
            .uncheckable()
            .field(std::move(props))
            .asMap();
    
}

static QVariantMap createProps_f4()
{
    using InnerField = demo2::message::Msg1Fields<>::F4Field;
    auto props =
        cc::property::field::ForField<InnerField>()
            .name(InnerField::name())
            .asMap();
    
    using Field = demo2::message::Msg1Fields<>::F4;
    return
        cc::property::field::ForField<Field>()
            .name(InnerField::name())
            .uncheckable()
            .field(std::move(props))
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_f1());
    props.append(createProps_f2());
    props.append(createProps_f3());
    props.append(createProps_f4());
    return props;
}

} // namespace

Msg1::Msg1() = default;
Msg1::~Msg1() = default;
Msg1& Msg1::operator=(const Msg1&) = default;
Msg1& Msg1::operator=(Msg1&&) = default;

const QVariantList& Msg1::fieldsPropertiesImpl() const
{
    static const QVariantList Props = createProps();
    return Props;
}

} // namespace message

} // namespace cc_plugin

} // namespace demo2


