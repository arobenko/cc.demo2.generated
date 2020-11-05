// Generated by commsdsl2comms v3.5.3

/// @file
/// @brief Contains definition of <b>"MsgId"</b> field.

#pragma once

#include <cstdint>
#include <type_traits>
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "demo2/MsgId.h"
#include "demo2/field/FieldBase.h"
#include "demo2/field/MsgIdCommon.h"
#include "demo2/options/DefaultOptions.h"

namespace demo2
{

namespace field
{

/// @brief Definition of <b>"MsgId"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = demo2::options::DefaultOptions, typename... TExtraOpts>
class MsgId : public
    comms::field::EnumValue<
        demo2::field::FieldBase<>,
        demo2::MsgId,
        TExtraOpts...,
        comms::option::def::ValidNumValueRange<1, 2>
    >
{
    using Base = 
        comms::field::EnumValue<
            demo2::field::FieldBase<>,
            demo2::MsgId,
            TExtraOpts...,
            comms::option::def::ValidNumValueRange<1, 2>
        >;
public:
    /// @brief Re-definition of the value type.
    using ValueType = typename Base::ValueType;

    /// @brief Name of the field.
    static const char* name()
    {
        return demo2::field::MsgIdCommon::name();
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(ValueType val)
    {
        return demo2::field::MsgIdCommon::valueName(val);
    }
    
    /// @brief Retrieve name of the @b current value
    const char* valueName() const
    {
        return valueName(Base::value());
    }
    
};

} // namespace field

} // namespace demo2


