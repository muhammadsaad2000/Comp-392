#pragma once

#include "lve_pipeline.hpp"
#include "lve_window.hpp"

namespace lve {
@@ -12,5 +13,6 @@ class FirstApp {

 private:
  LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
  LvePipeline lvePipeline{"shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv"};
};
} 