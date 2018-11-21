#pragma once

#include <tuple>
#include "cc_plugin/message/Msg1.h"
#include "cc_plugin/message/Msg2.h"

namespace demo2
{

namespace cc_plugin
{

using AllMessages =
    std::tuple<
        demo2::cc_plugin::message::Msg1,
        demo2::cc_plugin::message::Msg2
    >;

} // namespace cc_plugin

} // namespace demo2


