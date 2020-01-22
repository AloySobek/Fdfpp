/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfpp.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:50:39 by Rustam            #+#    #+#             */
/*   Updated: 2020/01/22 20:39:20 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.hpp"

int main(int argc, char **argv)
{
	VkInstance							instance{VK_NULL_HANDLE};
	VkInstanceCreateInfo				sInstanceCreateInfo{{}};
	VkAllocationCallbacks				sInstanceAllocation{{}};
	uint32_t							instanceExtCount{0};
	uint32_t							instanceLayCount{0};
	std::vector<VkExtensionProperties>	instanceExtensions;
	std::vector<VkLayerProperties>		instanceLayers;
	std::vector<char *>					desiredExt;
	std::vector<char *>					desiredLay;
	std::string							surf("VK_KHR_surface");
	std::string							swap("VK_MVK_macos_surface");
	uint32_t							error;

	vkEnumerateInstanceExtensionProperties(nullptr, &instanceExtCount, nullptr);
	instanceExtensions.resize(instanceExtCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &instanceExtCount, instanceExtensions.data());

	vkEnumerateInstanceLayerProperties(&instanceLayCount, nullptr);
	instanceLayers.resize(instanceLayCount);
	vkEnumerateInstanceLayerProperties(&instanceLayCount, instanceLayers.data());

	desiredExt.push_back((char *)surf.c_str());
	desiredExt.push_back((char *)swap.c_str());

	sInstanceCreateInfo.enabledExtensionCount = desiredExt.size();
	sInstanceCreateInfo.enabledLayerCount = desiredLay.size();
	sInstanceCreateInfo.ppEnabledExtensionNames = desiredExt.data();
	sInstanceCreateInfo.ppEnabledLayerNames = desiredLay.data();
	sInstanceCreateInfo.flags = VK_NULL_HANDLE;
	sInstanceCreateInfo.pNext = nullptr;
	sInstanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

	error = vkCreateInstance(&sInstanceCreateInfo, nullptr, &instance);
	if (error != VK_SUCCESS)
		std::cout << "ERROR\n";

	std::vector<VkPhysicalDevice>	devices;
	uint32_t						devicesCount{0};

	vkEnumeratePhysicalDevices(instance, &devicesCount, nullptr);
	devices.resize(devicesCount);
	vkEnumeratePhysicalDevices(instance, &devicesCount, devices.data());

	VkDevice								device{VK_NULL_HANDLE};
	VkDeviceCreateInfo						sDeviceCreateInfo{{}};
	std::vector<VkQueueFamilyProperties>	familyProperties;
	std::vector<VkDeviceQueueCreateInfo>	queueFamilyCreateInfos(1);
	uint32_t								queueFamilyPropertiesCount;
	uint32_t								computeIndex;
	VkPhysicalDeviceFeatures				deviceFeature;

	vkGetPhysicalDeviceQueueFamilyProperties(devices[0], &queueFamilyPropertiesCount, nullptr);
	familyProperties.resize(queueFamilyPropertiesCount);
	vkGetPhysicalDeviceQueueFamilyProperties(devices[0], &queueFamilyPropertiesCount, familyProperties.data());

	for (int i{0}; i < familyProperties.size(); ++i)
		if (familyProperties[i].queueCount > 0 && familyProperties[i].queueFlags & VK_QUEUE_COMPUTE_BIT)
		{
			computeIndex = i;
			break;
		}

	vkGetPhysicalDeviceFeatures(devices[0], &deviceFeature);
	float priority = 1.0f;

	queueFamilyCreateInfos[0].pNext = nullptr;
	queueFamilyCreateInfos[0].sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueFamilyCreateInfos[0].flags = VK_NULL_HANDLE;
	queueFamilyCreateInfos[0].pQueuePriorities = &priority;
	queueFamilyCreateInfos[0].queueCount = 1;
	queueFamilyCreateInfos[0].queueFamilyIndex = computeIndex;

	sDeviceCreateInfo.enabledExtensionCount		= 0;
	sDeviceCreateInfo.enabledLayerCount			= 0;
	sDeviceCreateInfo.ppEnabledExtensionNames	= nullptr;
	sDeviceCreateInfo.ppEnabledLayerNames		= nullptr;
	sDeviceCreateInfo.flags	= VK_NULL_HANDLE;
	sDeviceCreateInfo.pNext	= nullptr;
	sDeviceCreateInfo.sType	= VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	sDeviceCreateInfo.pEnabledFeatures		= &deviceFeature;
	sDeviceCreateInfo.queueCreateInfoCount	= 1;
	sDeviceCreateInfo.pQueueCreateInfos		= queueFamilyCreateInfos.data();

	error = vkCreateDevice(devices[0], &sDeviceCreateInfo, nullptr, &device);

	if (error != VK_SUCCESS)
		std::cout << "ERROR\n";

	VkImage				image = VK_NULL_HANDLE;
	VkImageCreateInfo	imageCreateInfo{{}};

	imageCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
	imageCreateInfo.pNext = nullptr;
	imageCreateInfo.flags = VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT;
	imageCreateInfo.arrayLayers = 1;
	imageCreateInfo.extent = {800, 600};
	imageCreateInfo.format = VK_FORMAT_R8G8B8A8_UNORM;
	imageCreateInfo.imageType = VK_IMAGE_TYPE_2D;
	imageCreateInfo.initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
	imageCreateInfo.mipLevels = 0;
	imageCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
	imageCreateInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
	imageCreateInfo.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
	imageCreateInfo.pQueueFamilyIndices = 0;
	imageCreateInfo.queueFamilyIndexCount = 0;
	imageCreateInfo.samples = VK_SAMPLE_COUNT_1_BIT;

	error = vkCreateImage(device, &imageCreateInfo, nullptr, &image);
	if (error != VK_SUCCESS)
		std::cout << "ERROR\n" << error;

	VkMemoryRequirements	sImageMemReq;

	vkGetImageMemoryRequirements(device, image, &sImageMemReq);

	VkMemoryAllocateInfo	sMemAllocInfo;

	sMemAllocInfo.allocationSize = sImageMemReq.size;
	sMemAllocInfo.memoryTypeIndex = sImageMemReq.memoryTypeBits;
	sMemAllocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;

	return (0);
}
