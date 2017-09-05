/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package dialog.rpc;


import java.util.Map;
import java.util.HashMap;
import org.apache.thrift.TEnum;

public enum rpc_storage_mode implements org.apache.thrift.TEnum {
  RPC_IN_MEMORY(0),
  RPC_DURABLE_RELAXED(1),
  RPC_DURABLE(2);

  private final int value;

  private rpc_storage_mode(int value) {
    this.value = value;
  }

  /**
   * Get the integer value of this enum value, as defined in the Thrift IDL.
   */
  public int getValue() {
    return value;
  }

  /**
   * Find a the enum type by its integer value, as defined in the Thrift IDL.
   * @return null if the value is not found.
   */
  public static rpc_storage_mode findByValue(int value) { 
    switch (value) {
      case 0:
        return RPC_IN_MEMORY;
      case 1:
        return RPC_DURABLE_RELAXED;
      case 2:
        return RPC_DURABLE;
      default:
        return null;
    }
  }
}
