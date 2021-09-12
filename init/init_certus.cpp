/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>

#include "init_certus.h"

constexpr auto CACTUS_BOARD_ID = "S98506";
constexpr auto CEREUS_BOARD_ID = "S98507";

constexpr auto CMDLINE_PATH = "/proc/cmdline";
constexpr auto CMDLINE_BOARD_ID = "board_id";

using android::base::ReadFileToString;
using android::base::Split;
using android::base::Trim;

constexpr auto
	CACTUS_PROPERTIES = properties{"Redmi 6A", "cactus", "cactus-user 9 PPR1.180610.011 V11.0.9.0.PCBMIXM release-keys",
	                               "xiaomi/cactus/cactus:9/PPR1.180610.011/V11.0.9.0.PCBMIXM:user/release-keys"};

constexpr auto
	CEREUS_PROPERTIES = properties{"Redmi 6", "cereus", "cereus-user 9 PPR1.180610.011 V11.0.5.0.PCGMIXM release-keys",
	                               "xiaomi/cereus/cereus:9/PPR1.180610.011/V11.0.5.0.PCGMIXM:user/release-keys"};

bool get_board_id(std::string &out) {
	std::string str;

	if (!ReadFileToString(CMDLINE_PATH, &str)) {
		LOG(ERROR) << "Unable to open: " << CMDLINE_PATH;
		return false;
	}

	for (const auto &entry : Split(Trim(str), " ")) {
		std::vector<std::string> pieces = Split(entry, "=");

		if (pieces.size() == 2 && pieces.at(0) == CMDLINE_BOARD_ID) {
			out = pieces.at(1);
			std::transform(out.begin(), out.end(), out.begin(), ::toupper);
			return true;
		}
	}

	return false;
}

bool get_properties(properties &props) {
	std::string board_id;

	if (!get_board_id(board_id)) {
		return false;
	}

	if (board_id.find(CACTUS_BOARD_ID) != std::string::npos) {
		props = CACTUS_PROPERTIES;
	} else if (board_id.find(CEREUS_BOARD_ID) != std::string::npos) {
		props = CEREUS_PROPERTIES;
	} else {
		LOG(ERROR) << "Unsupported board id " << board_id;
		return false;
	}

	return true;
}
