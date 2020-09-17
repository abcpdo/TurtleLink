// Auto-generated. Do not edit!

// (in-package rsp_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Message {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.q0 = null;
      this.q1 = null;
      this.q2 = null;
      this.q3 = null;
    }
    else {
      if (initObj.hasOwnProperty('q0')) {
        this.q0 = initObj.q0
      }
      else {
        this.q0 = 0;
      }
      if (initObj.hasOwnProperty('q1')) {
        this.q1 = initObj.q1
      }
      else {
        this.q1 = 0;
      }
      if (initObj.hasOwnProperty('q2')) {
        this.q2 = initObj.q2
      }
      else {
        this.q2 = 0;
      }
      if (initObj.hasOwnProperty('q3')) {
        this.q3 = initObj.q3
      }
      else {
        this.q3 = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Message
    // Serialize message field [q0]
    bufferOffset = _serializer.uint32(obj.q0, buffer, bufferOffset);
    // Serialize message field [q1]
    bufferOffset = _serializer.uint32(obj.q1, buffer, bufferOffset);
    // Serialize message field [q2]
    bufferOffset = _serializer.uint32(obj.q2, buffer, bufferOffset);
    // Serialize message field [q3]
    bufferOffset = _serializer.uint32(obj.q3, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Message
    let len;
    let data = new Message(null);
    // Deserialize message field [q0]
    data.q0 = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [q1]
    data.q1 = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [q2]
    data.q2 = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [q3]
    data.q3 = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rsp_msgs/Message';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2ff38cde609e9b3b19927a6880a3e6ba';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 q0
    uint32 q1
    uint32 q2
    uint32 q3
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Message(null);
    if (msg.q0 !== undefined) {
      resolved.q0 = msg.q0;
    }
    else {
      resolved.q0 = 0
    }

    if (msg.q1 !== undefined) {
      resolved.q1 = msg.q1;
    }
    else {
      resolved.q1 = 0
    }

    if (msg.q2 !== undefined) {
      resolved.q2 = msg.q2;
    }
    else {
      resolved.q2 = 0
    }

    if (msg.q3 !== undefined) {
      resolved.q3 = msg.q3;
    }
    else {
      resolved.q3 = 0
    }

    return resolved;
    }
};

module.exports = Message;