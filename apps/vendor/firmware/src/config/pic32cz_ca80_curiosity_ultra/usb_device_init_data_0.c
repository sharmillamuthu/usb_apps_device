/*******************************************************************************
  System Initialization File

  File Name:
    usb_device_init_data.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "definitions.h"
/**************************************************
 * USB Device Function Driver Init Data
 **************************************************/


/**************************************************
 * USB Device Layer Function Driver Registration 
 * Table
 **************************************************/
const USB_DEVICE_FUNCTION_REGISTRATION_TABLE funcRegistrationTable0[1] =
{
    
	/* Vendor Function 0 */
    { 
        .configurationValue = 1,    /* Configuration value */ 
        .interfaceNumber = 0,       /* First interfaceNumber of this function */ 
        .speed = USB_SPEED_HIGH|USB_SPEED_FULL,    /* Function Speed */ 
        .numberOfInterfaces = 1,    /* Number of interfaces */
        .funcDriverIndex = 0,  /* Index of Function Driver */
        .driver = NULL,    
        .funcDriverInit = NULL    /* Function driver init data */
    },



};

/*******************************************
 * USB Device Layer Descriptors
 *******************************************/
/*******************************************
 *  USB Device Descriptor 
 *******************************************/
const USB_DEVICE_DESCRIPTOR deviceDescriptor0 =
{
    0x12,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_DEVICE,                                  // DEVICE descriptor type
    0x0200,                                                 // USB Spec Release Number in BCD format
        0x00,         // Class Code
    0x00,         // Subclass code
    0x00,         // Protocol code


    USB_DEVICE_EP0_BUFFER_SIZE,                             // Max packet size for EP0, see configuration.h
    0x04D8,                                                 // Vendor ID
    0x0053,                                                 // Product ID                
    0x0100,                                                 // Device release number in BCD format
    0x01,                                                   // Manufacturer string index
    0x02,                                                   // Product string index
    0x00,                                                   // Device serial number string index
    0x01                                                    // Number of possible configurations
};


/*******************************************
 *  USB Device Qualifier Descriptor for this
 *  demo.
 *******************************************/
const USB_DEVICE_QUALIFIER deviceQualifierDescriptor0 =
{
    0x0A,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_DEVICE_QUALIFIER,                        // Device Qualifier Type
    0x0200,                                                 // USB Specification Release number
        0x00,         // Class Code
    0x00,         // Subclass code
    0x00,         // Protocol code


    USB_DEVICE_EP0_BUFFER_SIZE,                             // Maximum packet size for endpoint 0
    0x01,                                                   // Number of possible configurations
    0x00                                                    // Reserved for future use.
};

/*******************************************
 *  USB High Speed Configuration Descriptor
 *******************************************/
const uint8_t highSpeedConfigurationDescriptor0[]=
{
    /* Configuration Descriptor */

    0x09,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_CONFIGURATION,                           // Descriptor Type
    USB_DEVICE_16bitTo8bitArrange(32),                      //(32 Bytes)Size of the Configuration descriptor
    1,                                                      // Number of interfaces in this configuration
    0x01,                                               // Index value of this configuration
    0x00,                                               // Configuration string index
    USB_ATTRIBUTE_DEFAULT | USB_ATTRIBUTE_SELF_POWERED, // Attributes
    50,                                                 // Maximum power consumption (mA) /2
    
	/* Interface Descriptor */

    0x09,                       // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,   // INTERFACE descriptor type
    0,                          // Interface Number
    0,                          // Alternate Setting Number
    2,                          // Number of endpoints in this intf
    0xFF,                       // Class code
    0xFF,                       // Subclass code
    0xFF,                       // Protocol code
    0,                          // Interface string index

    /* Endpoint (OUT) Descriptor */

    0x07,                       // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor 
    1 | USB_EP_DIRECTION_OUT,   // EndpointAddress ( EP1 OUT )
    USB_TRANSFER_TYPE_BULK,     // Attributes
    0x00,0x02,                  // Max packet size of this EP
    1,                          // Interval

    /* Endpoint (IN) Descriptor */

    0x07,                       // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    1 | USB_EP_DIRECTION_IN,    // EndpointAddress ( EP1 IN )
    USB_TRANSFER_TYPE_BULK,     // Attributes
    0x00,0x02,                  // Max packet size of this EP
    1,                          // Interval



};

/*******************************************
 * Array of High speed config descriptors
 *******************************************/
USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE highSpeedConfigDescSet0[1] =
{
    highSpeedConfigurationDescriptor0
};

/*******************************************
 *  USB Full Speed Configuration Descriptor
 *******************************************/
const uint8_t fullSpeedConfigurationDescriptor0[]=
{
    /* Configuration Descriptor */

    0x09,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_CONFIGURATION,                           // Descriptor Type
    USB_DEVICE_16bitTo8bitArrange(32),                      //(32 Bytes)Size of the Configuration descriptor
    1,                                                      // Number of interfaces in this configuration
    0x01,                                                   // Index value of this configuration
    0x00,                                                   // Configuration string index
    USB_ATTRIBUTE_DEFAULT | USB_ATTRIBUTE_SELF_POWERED, // Attributes
    50,                                                 // Maximum power consumption (mA) /2    
	/* Interface Descriptor */

    0x09,                       // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,   // INTERFACE descriptor type
    0,                          // Interface Number
    0,                          // Alternate Setting Number
    2,                          // Number of endpoints in this intf
    0xFF,                       // Class code
    0xFF,                       // Subclass code
    0xFF,                       // Protocol code
    0,                          // Interface string index

    /* Endpoint (OUT) Descriptor */

    0x07,                       // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor 
    1 | USB_EP_DIRECTION_OUT,   // EndpointAddress ( EP1 OUT )
    USB_TRANSFER_TYPE_BULK,     // Attributes
    0x40,0x00,                  // Max packet size of this EP
    1,                          // Interval

    /* Endpoint (IN) Descriptor */

    0x07,                       // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    1 | USB_EP_DIRECTION_IN,    // EndpointAddress ( EP1 IN )
    USB_TRANSFER_TYPE_BULK,     // Attributes
    0x40,0x00,                  // Max packet size of this EP
    1,                          // Interval



};

/*******************************************
 * Array of Full speed Configuration 
 * descriptors
 *******************************************/
USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE fullSpeedConfigDescSet0[1] =
{
    fullSpeedConfigurationDescriptor0
};


/**************************************
 *  String descriptors.
 *************************************/
 /*******************************************
 *  Language code string descriptor
 *******************************************/
const struct
{
    uint8_t bLength;
    uint8_t bDscType;
    uint16_t string[1];
}

sd000_0 =
{
    sizeof(sd000_0),                                      // Size of this descriptor in bytes
    USB_DESCRIPTOR_STRING,                              // STRING descriptor type
    {0x0409}                                            // Language ID
};
/*******************************************
 *  Manufacturer string descriptor
 *******************************************/
const struct
{
    uint8_t bLength;                                    // Size of this descriptor in bytes
    uint8_t bDscType;                                   // STRING descriptor type
    uint16_t string[25];                                // String
}

sd001_0 =
{
    sizeof(sd001_0),
    USB_DESCRIPTOR_STRING,
    {'M','i','c','r','o','c','h','i','p',' ','T','e','c','h','n','o','l','o','g','y',' ','I','n','c','.'}
    };

/*******************************************
 *  Product string descriptor
 *******************************************/
const struct
{
    uint8_t bLength;                                    // Size of this descriptor in bytes
    uint8_t bDscType;                                   // STRING descriptor type
    uint16_t string[25];                                // String
}

sd002_0 =
{
    sizeof(sd002_0),
    USB_DESCRIPTOR_STRING,
    {'S','i','m','p','l','e',' ','W','i','n','U','S','B',' ','D','e','v','i','c','e',' ','D','e','m','o'}
}; 

/***************************************
 * Array of string descriptors
 ***************************************/
USB_DEVICE_STRING_DESCRIPTORS_TABLE stringDescriptors0[3]=
{
    (const uint8_t *const)&sd000_0,
    (const uint8_t *const)&sd001_0,
    (const uint8_t *const)&sd002_0,
};

/*******************************************
 * USB Device Layer Master Descriptor Table 
 *******************************************/
const USB_DEVICE_MASTER_DESCRIPTOR usbMasterDescriptor0 =
{
    &deviceDescriptor0,                                      // Full speed descriptor
    1,                                                      // Total number of full speed configurations available
    fullSpeedConfigDescSet0,                // Pointer to array of full speed configurations descriptors
    &deviceDescriptor0,                     // High speed device descriptor
    1,                                                      // Total number of high speed configurations available
    highSpeedConfigDescSet0,                                 // Pointer to array of high speed configurations descriptors
    3,                                                      // Total number of string descriptors available.
    stringDescriptors0,                     // Pointer to array of string descriptors.
    &deviceQualifierDescriptor0,                            // Pointer to full speed dev qualifier.
    &deviceQualifierDescriptor0                             // Pointer to high speed dev qualifier.
};


/****************************************************
 * USB Device Layer Initialization Data
 ****************************************************/
const USB_DEVICE_INIT usbDevInitData0 =
{
    /* Number of function drivers registered to this instance of the
       USB device layer */
    .registeredFuncCount = 1,
    
    /* Function driver table registered to this instance of the USB device layer*/
    .registeredFunctions = (USB_DEVICE_FUNCTION_REGISTRATION_TABLE*)funcRegistrationTable0,

    /* Pointer to USB Descriptor structure */
    .usbMasterDescriptor = (USB_DEVICE_MASTER_DESCRIPTOR*)&usbMasterDescriptor0,

    /* USB Device Speed */
    .deviceSpeed =  USB_SPEED_HIGH,   
    
    /* Index of the USB Driver to be used by this Device Layer Instance */
    .driverIndex = DRV_USBHS_INDEX_0,

    /* Pointer to the USB Driver Functions. */
    .usbDriverInterface = DRV_USBHS_DEVICE_INTERFACE,
    
    /* Specify queue size for vendor endpoint read */
    .queueSizeEndpointRead = 1,
    
    /* Specify queue size for vendor endpoint write */
    .queueSizeEndpointWrite= 1
};
// </editor-fold>
