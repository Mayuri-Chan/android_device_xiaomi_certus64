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

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <string>

#include "init_certus.h"

void property_override(const std::string &key, const std::string &value) {
	auto pi = (prop_info *) __system_property_find(key.c_str());

	if (pi != nullptr) {
		__system_property_update(pi, value.c_str(), value.size());
	} else {
		__system_property_add(key.c_str(), key.size(), value.c_str(), value.size());
	}
}

void vendor_load_properties() {
	properties props;

	if (get_properties(props)) {
		property_override("ro.secure", "0");
		property_override("ro.adb.secure", "0");

		property_override("ro.product.device", props.codename);
		property_override("ro.product.odm.device", props.codename);
		property_override("ro.product.system.device", props.codename);

		property_override("ro.product.name", props.codename);
		property_override("ro.product.odm.name", props.codename);
		property_override("ro.product.system.name", props.codename);

		property_override("ro.product.model", props.model);
		property_override("ro.product.odm.model", props.model);
		property_override("ro.product.system.model", props.model);

		property_override("ro.build.product", props.codename);
		property_override("ro.build.description", props.description);

		property_override("ro.build.fingerprint", props.fingerprint);
		property_override("ro.odm.build.fingerprint", props.fingerprint);
		property_override("ro.system.build.fingerprint", props.fingerprint);
		property_override("ro.bootimage.build.fingerprint", props.fingerprint);
	}
}
