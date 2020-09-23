; Auto-generated. Do not edit!


(cl:in-package meturone_egitim-msg)


;//! \htmlinclude Dummy.msg.html

(cl:defclass <Dummy> (roslisp-msg-protocol:ros-message)
  ((n
    :reader n
    :initarg :n
    :type cl:integer
    :initform 0)
   (arr
    :reader arr
    :initarg :arr
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass Dummy (<Dummy>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Dummy>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Dummy)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name meturone_egitim-msg:<Dummy> is deprecated: use meturone_egitim-msg:Dummy instead.")))

(cl:ensure-generic-function 'n-val :lambda-list '(m))
(cl:defmethod n-val ((m <Dummy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader meturone_egitim-msg:n-val is deprecated.  Use meturone_egitim-msg:n instead.")
  (n m))

(cl:ensure-generic-function 'arr-val :lambda-list '(m))
(cl:defmethod arr-val ((m <Dummy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader meturone_egitim-msg:arr-val is deprecated.  Use meturone_egitim-msg:arr instead.")
  (arr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Dummy>) ostream)
  "Serializes a message object of type '<Dummy>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'n)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'n)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'n)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'arr))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'arr))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Dummy>) istream)
  "Deserializes a message object of type '<Dummy>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'n)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'n)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'n)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'arr) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'arr)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Dummy>)))
  "Returns string type for a message object of type '<Dummy>"
  "meturone_egitim/Dummy")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Dummy)))
  "Returns string type for a message object of type 'Dummy"
  "meturone_egitim/Dummy")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Dummy>)))
  "Returns md5sum for a message object of type '<Dummy>"
  "a28c53ac425b05d14c304bbe6886d48e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Dummy)))
  "Returns md5sum for a message object of type 'Dummy"
  "a28c53ac425b05d14c304bbe6886d48e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Dummy>)))
  "Returns full string definition for message of type '<Dummy>"
  (cl:format cl:nil "uint32 n~%int32[] arr~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Dummy)))
  "Returns full string definition for message of type 'Dummy"
  (cl:format cl:nil "uint32 n~%int32[] arr~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Dummy>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'arr) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Dummy>))
  "Converts a ROS message object to a list"
  (cl:list 'Dummy
    (cl:cons ':n (n msg))
    (cl:cons ':arr (arr msg))
))
