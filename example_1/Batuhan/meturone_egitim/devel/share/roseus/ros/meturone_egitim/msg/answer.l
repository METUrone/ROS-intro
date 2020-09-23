;; Auto-generated. Do not edit!


(when (boundp 'meturone_egitim::answer)
  (if (not (find-package "METURONE_EGITIM"))
    (make-package "METURONE_EGITIM"))
  (shadow 'answer (find-package "METURONE_EGITIM")))
(unless (find-package "METURONE_EGITIM::ANSWER")
  (make-package "METURONE_EGITIM::ANSWER"))

(in-package "ROS")
;;//! \htmlinclude answer.msg.html


(defclass meturone_egitim::answer
  :super ros::object
  :slots (_sum ))

(defmethod meturone_egitim::answer
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get meturone_egitim::answer :md5sum-) "0ba699c25c9418c0366f3595c0c8e8ec")
(setf (get meturone_egitim::answer :datatype-) "meturone_egitim/answer")
(setf (get meturone_egitim::answer :definition-)
      "int32 sum

")



(provide :meturone_egitim/answer "0ba699c25c9418c0366f3595c0c8e8ec")


