;; Auto-generated. Do not edit!


(when (boundp 'meturone_egitim::Dummy)
  (if (not (find-package "METURONE_EGITIM"))
    (make-package "METURONE_EGITIM"))
  (shadow 'Dummy (find-package "METURONE_EGITIM")))
(unless (find-package "METURONE_EGITIM::DUMMY")
  (make-package "METURONE_EGITIM::DUMMY"))

(in-package "ROS")
;;//! \htmlinclude Dummy.msg.html


(defclass meturone_egitim::Dummy
  :super ros::object
  :slots (_n _arr ))

(defmethod meturone_egitim::Dummy
  (:init
   (&key
    ((:n __n) 0)
    ((:arr __arr) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _n (round __n))
   (setq _arr __arr)
   self)
  (:n
   (&optional __n)
   (if __n (setq _n __n)) _n)
  (:arr
   (&optional __arr)
   (if __arr (setq _arr __arr)) _arr)
  (:serialization-length
   ()
   (+
    ;; uint32 _n
    4
    ;; int32[] _arr
    (* 4    (length _arr)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _n
       (write-long _n s)
     ;; int32[] _arr
     (write-long (length _arr) s)
     (dotimes (i (length _arr))
       (write-long (elt _arr i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _n
     (setq _n (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32[] _arr
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _arr (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _arr i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get meturone_egitim::Dummy :md5sum-) "a28c53ac425b05d14c304bbe6886d48e")
(setf (get meturone_egitim::Dummy :datatype-) "meturone_egitim/Dummy")
(setf (get meturone_egitim::Dummy :definition-)
      "uint32 n
int32[] arr
")



(provide :meturone_egitim/Dummy "a28c53ac425b05d14c304bbe6886d48e")


