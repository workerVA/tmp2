/*
 * Copyright 2015 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef __TPM2_OBJECT_FP_H
#define __TPM2_OBJECT_FP_H

void ObjectComputeName(
        TPMT_PUBLIC         *publicArea,       // IN: public area of an object
        TPM2B_NAME          *name              // OUT: name of the object
);
TPM_RC ObjectContextLoad(
        OBJECT              *object,               // IN: object structure from saved context
        TPMI_DH_OBJECT      *handle                // OUT: object handle
                         );
TPMI_RH_HIERARCHY ObjectDataGetHierarchy(
        OBJECT              *object             // IN :object
);
void ObjectFlushHierarchy(
        TPMI_RH_HIERARCHY          hierarchy             // IN: hierarchy to be flush
);
OBJECT* ObjectGet(
        TPMI_DH_OBJECT       handle             // IN: handle of the object
);
UINT16 ObjectGetName(
        TPMI_DH_OBJECT       handle,            // IN: handle of the object
        NAME                *name               // OUT: name of the object
);
void ObjectGetQualifiedName(
        TPMI_DH_OBJECT       handle,            // IN: handle of the object
        TPM2B_NAME          *qualifiedName      // OUT: qualified name of the object
);
BOOL ObjectIsSequence(
        OBJECT              *object               // IN: handle to be checked
                      );
BOOL ObjectIsStorage(
        TPMI_DH_OBJECT     handle              // IN: object handle
        );
TPM_RC ObjectLoad(
        TPMI_RH_HIERARCHY        hierarchy,               //   IN: hierarchy to which the object belongs
        TPMT_PUBLIC             *publicArea,              //   IN: public area
        TPMT_SENSITIVE          *sensitive,               //   IN: sensitive area (may be null)
        TPM2B_NAME              *name,                    //   IN: object's name (may be null)
        TPM_HANDLE               parentHandle,            //   IN: handle of parent
        BOOL                     skipChecks,              //   IN: flag to indicate if it is OK to skip
                                                     //       consistency checks.
        TPMI_DH_OBJECT          *handle                   //   OUT: object handle
);

#endif // __TPM2_OBJECT_FP_H
