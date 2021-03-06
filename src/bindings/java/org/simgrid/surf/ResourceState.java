/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.simgrid.surf;

public final class ResourceState {
  public final static ResourceState SURF_RESOURCE_ON = new ResourceState("SURF_RESOURCE_ON", SurfJNI.SURF_RESOURCE_ON_get());
  public final static ResourceState SURF_RESOURCE_OFF = new ResourceState("SURF_RESOURCE_OFF", SurfJNI.SURF_RESOURCE_OFF_get());

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static ResourceState swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + ResourceState.class + " with value " + swigValue);
  }

  private ResourceState(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private ResourceState(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private ResourceState(String swigName, ResourceState swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static ResourceState[] swigValues = { SURF_RESOURCE_ON, SURF_RESOURCE_OFF };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}

