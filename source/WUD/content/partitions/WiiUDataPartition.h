/****************************************************************************
 * Copyright (C) 2016-2021 Maschell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#pragma once

#include <cstdint>
#include <cstdlib>
#include <WUD/entities/FST/FST.h>
#include <utils/blocksize/AddressInDiscBlocks.h>
#include "WiiUPartition.h"

class WiiUDataPartition : public WiiUPartition {

public:
    WiiUDataPartition(WiiUPartition *partition, FST *pFST);

    ~WiiUDataPartition() override;

    [[nodiscard]] std::string getVolumeId() const & override;

    [[nodiscard]] std::map<AddressInDiscBlocks, VolumeHeader *> getVolumes() const & override;

    [[nodiscard]] uint16_t getFileSystemDescriptor() const override;


    [[nodiscard]] uint64_t getSectionOffsetOnDefaultPartition() override;

    FST *fst{};

private:
    WiiUPartition *basePartition;
};
