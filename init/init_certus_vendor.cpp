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

#include <cutils/properties.h>
#include <cstdlib>

#include "init_certus.h"

int main() {
	properties props;

	if (get_properties(props)) {
		property_set("ro.product.vendor.device", props.codename);
		property_set("ro.product.vendor.model", props.model);
		property_set("ro.product.vendor.name", props.codename);

		property_set("ro.bootimage.build.fingerprint", props.fingerprint);
		property_set("ro.vendor.build.fingerprint", props.fingerprint);
	}
}
