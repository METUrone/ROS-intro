// Auto-generated. Do not edit!

// (in-package meturone_egitim.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Dummy {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.n = null;
      this.arr = null;
    }
    else {
      if (initObj.hasOwnProperty('n')) {
        this.n = initObj.n
      }
      else {
        this.n = 0;
      }
      if (initObj.hasOwnProperty('arr')) {
        this.arr = initObj.arr
      }
      else {
        this.arr = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Dummy
    // Serialize message field [n]
    bufferOffset = _serializer.uint32(obj.n, buffer, bufferOffset);
    // Serialize message field [arr]
    bufferOffset = _arraySerializer.int32(obj.arr, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Dummy
    let len;
    let data = new Dummy(null);
    // Deserialize message field [n]
    data.n = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [arr]
    data.arr = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.arr.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'meturone_egitim/Dummy';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a28c53ac425b05d14c304bbe6886d48e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 n
    int32[] arr
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Dummy(null);
    if (msg.n !== undefined) {
      resolved.n = msg.n;
    }
    else {
      resolved.n = 0
    }

    if (msg.arr !== undefined) {
      resolved.arr = msg.arr;
    }
    else {
      resolved.arr = []
    }

    return resolved;
    }
};

module.exports = Dummy;
