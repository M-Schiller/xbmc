/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "utils/IBufferObject.h"

#include <stdint.h>

struct gbm_bo;
struct gbm_device;

class CGBMBufferObject : public IBufferObject
{
public:
  CGBMBufferObject();
  ~CGBMBufferObject() override;

  bool CreateBufferObject(uint32_t format, uint32_t width, uint32_t height) override;
  void DestroyBufferObject() override;
  uint8_t* GetMemory() override;
  void ReleaseMemory() override;
  int GetFd() override;
  uint32_t GetStride() override;
  uint64_t GetModifier();

private:
  gbm_device *m_device = nullptr;

  int m_fd = -1;
  uint32_t m_width{0};
  uint32_t m_height{0};
  uint32_t m_stride = 0;
  uint8_t *m_map = nullptr;
  void *m_map_data = nullptr;
  gbm_bo *m_bo = nullptr;
};
