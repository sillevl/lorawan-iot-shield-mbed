#pragma once

namespace IoTShield {

  class ITouchEventHandler {

    public:
      virtual void touch_event_occured(TouchEvent event);

  };

};
