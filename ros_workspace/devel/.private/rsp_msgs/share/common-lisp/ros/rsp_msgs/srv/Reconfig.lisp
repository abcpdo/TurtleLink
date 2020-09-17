; Auto-generated. Do not edit!


(cl:in-package rsp_msgs-srv)


;//! \htmlinclude Reconfig-request.msg.html

(cl:defclass <Reconfig-request> (roslisp-msg-protocol:ros-message)
  ((configuration
    :reader configuration
    :initarg :configuration
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Reconfig-request (<Reconfig-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Reconfig-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Reconfig-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rsp_msgs-srv:<Reconfig-request> is deprecated: use rsp_msgs-srv:Reconfig-request instead.")))

(cl:ensure-generic-function 'configuration-val :lambda-list '(m))
(cl:defmethod configuration-val ((m <Reconfig-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rsp_msgs-srv:configuration-val is deprecated.  Use rsp_msgs-srv:configuration instead.")
  (configuration m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Reconfig-request>) ostream)
  "Serializes a message object of type '<Reconfig-request>"
  (cl:let* ((signed (cl:slot-value msg 'configuration)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Reconfig-request>) istream)
  "Deserializes a message object of type '<Reconfig-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'configuration) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Reconfig-request>)))
  "Returns string type for a service object of type '<Reconfig-request>"
  "rsp_msgs/ReconfigRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Reconfig-request)))
  "Returns string type for a service object of type 'Reconfig-request"
  "rsp_msgs/ReconfigRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Reconfig-request>)))
  "Returns md5sum for a message object of type '<Reconfig-request>"
  "fd27df16901bf0767f619a2a1147b980")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Reconfig-request)))
  "Returns md5sum for a message object of type 'Reconfig-request"
  "fd27df16901bf0767f619a2a1147b980")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Reconfig-request>)))
  "Returns full string definition for message of type '<Reconfig-request>"
  (cl:format cl:nil "int16 configuration~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Reconfig-request)))
  "Returns full string definition for message of type 'Reconfig-request"
  (cl:format cl:nil "int16 configuration~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Reconfig-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Reconfig-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Reconfig-request
    (cl:cons ':configuration (configuration msg))
))
;//! \htmlinclude Reconfig-response.msg.html

(cl:defclass <Reconfig-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Reconfig-response (<Reconfig-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Reconfig-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Reconfig-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rsp_msgs-srv:<Reconfig-response> is deprecated: use rsp_msgs-srv:Reconfig-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <Reconfig-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rsp_msgs-srv:success-val is deprecated.  Use rsp_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Reconfig-response>) ostream)
  "Serializes a message object of type '<Reconfig-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Reconfig-response>) istream)
  "Deserializes a message object of type '<Reconfig-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Reconfig-response>)))
  "Returns string type for a service object of type '<Reconfig-response>"
  "rsp_msgs/ReconfigResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Reconfig-response)))
  "Returns string type for a service object of type 'Reconfig-response"
  "rsp_msgs/ReconfigResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Reconfig-response>)))
  "Returns md5sum for a message object of type '<Reconfig-response>"
  "fd27df16901bf0767f619a2a1147b980")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Reconfig-response)))
  "Returns md5sum for a message object of type 'Reconfig-response"
  "fd27df16901bf0767f619a2a1147b980")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Reconfig-response>)))
  "Returns full string definition for message of type '<Reconfig-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Reconfig-response)))
  "Returns full string definition for message of type 'Reconfig-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Reconfig-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Reconfig-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Reconfig-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Reconfig)))
  'Reconfig-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Reconfig)))
  'Reconfig-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Reconfig)))
  "Returns string type for a service object of type '<Reconfig>"
  "rsp_msgs/Reconfig")