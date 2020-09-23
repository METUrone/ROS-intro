; Auto-generated. Do not edit!


(cl:in-package meturone_egitim-msg)


;//! \htmlinclude answer.msg.html

(cl:defclass <answer> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type cl:integer
    :initform 0))
)

(cl:defclass answer (<answer>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <answer>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'answer)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name meturone_egitim-msg:<answer> is deprecated: use meturone_egitim-msg:answer instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <answer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader meturone_egitim-msg:sum-val is deprecated.  Use meturone_egitim-msg:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <answer>) ostream)
  "Serializes a message object of type '<answer>"
  (cl:let* ((signed (cl:slot-value msg 'sum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <answer>) istream)
  "Deserializes a message object of type '<answer>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<answer>)))
  "Returns string type for a message object of type '<answer>"
  "meturone_egitim/answer")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'answer)))
  "Returns string type for a message object of type 'answer"
  "meturone_egitim/answer")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<answer>)))
  "Returns md5sum for a message object of type '<answer>"
  "0ba699c25c9418c0366f3595c0c8e8ec")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'answer)))
  "Returns md5sum for a message object of type 'answer"
  "0ba699c25c9418c0366f3595c0c8e8ec")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<answer>)))
  "Returns full string definition for message of type '<answer>"
  (cl:format cl:nil "int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'answer)))
  "Returns full string definition for message of type 'answer"
  (cl:format cl:nil "int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <answer>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <answer>))
  "Converts a ROS message object to a list"
  (cl:list 'answer
    (cl:cons ':sum (sum msg))
))
