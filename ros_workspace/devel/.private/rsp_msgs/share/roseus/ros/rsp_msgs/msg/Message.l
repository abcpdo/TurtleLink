;; Auto-generated. Do not edit!


(when (boundp 'rsp_msgs::Message)
  (if (not (find-package "RSP_MSGS"))
    (make-package "RSP_MSGS"))
  (shadow 'Message (find-package "RSP_MSGS")))
(unless (find-package "RSP_MSGS::MESSAGE")
  (make-package "RSP_MSGS::MESSAGE"))

(in-package "ROS")
;;//! \htmlinclude Message.msg.html


(defclass rsp_msgs::Message
  :super ros::object
  :slots (_q0 _q1 _q2 _q3 ))

(defmethod rsp_msgs::Message
  (:init
   (&key
    ((:q0 __q0) 0)
    ((:q1 __q1) 0)
    ((:q2 __q2) 0)
    ((:q3 __q3) 0)
    )
   (send-super :init)
   (setq _q0 (round __q0))
   (setq _q1 (round __q1))
   (setq _q2 (round __q2))
   (setq _q3 (round __q3))
   self)
  (:q0
   (&optional __q0)
   (if __q0 (setq _q0 __q0)) _q0)
  (:q1
   (&optional __q1)
   (if __q1 (setq _q1 __q1)) _q1)
  (:q2
   (&optional __q2)
   (if __q2 (setq _q2 __q2)) _q2)
  (:q3
   (&optional __q3)
   (if __q3 (setq _q3 __q3)) _q3)
  (:serialization-length
   ()
   (+
    ;; uint32 _q0
    4
    ;; uint32 _q1
    4
    ;; uint32 _q2
    4
    ;; uint32 _q3
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _q0
       (write-long _q0 s)
     ;; uint32 _q1
       (write-long _q1 s)
     ;; uint32 _q2
       (write-long _q2 s)
     ;; uint32 _q3
       (write-long _q3 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _q0
     (setq _q0 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _q1
     (setq _q1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _q2
     (setq _q2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _q3
     (setq _q3 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get rsp_msgs::Message :md5sum-) "2ff38cde609e9b3b19927a6880a3e6ba")
(setf (get rsp_msgs::Message :datatype-) "rsp_msgs/Message")
(setf (get rsp_msgs::Message :definition-)
      "uint32 q0
uint32 q1
uint32 q2
uint32 q3

")



(provide :rsp_msgs/Message "2ff38cde609e9b3b19927a6880a3e6ba")


