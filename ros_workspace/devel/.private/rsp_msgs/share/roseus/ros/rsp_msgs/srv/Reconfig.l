;; Auto-generated. Do not edit!


(when (boundp 'rsp_msgs::Reconfig)
  (if (not (find-package "RSP_MSGS"))
    (make-package "RSP_MSGS"))
  (shadow 'Reconfig (find-package "RSP_MSGS")))
(unless (find-package "RSP_MSGS::RECONFIG")
  (make-package "RSP_MSGS::RECONFIG"))
(unless (find-package "RSP_MSGS::RECONFIGREQUEST")
  (make-package "RSP_MSGS::RECONFIGREQUEST"))
(unless (find-package "RSP_MSGS::RECONFIGRESPONSE")
  (make-package "RSP_MSGS::RECONFIGRESPONSE"))

(in-package "ROS")





(defclass rsp_msgs::ReconfigRequest
  :super ros::object
  :slots (_configuration ))

(defmethod rsp_msgs::ReconfigRequest
  (:init
   (&key
    ((:configuration __configuration) 0)
    )
   (send-super :init)
   (setq _configuration (round __configuration))
   self)
  (:configuration
   (&optional __configuration)
   (if __configuration (setq _configuration __configuration)) _configuration)
  (:serialization-length
   ()
   (+
    ;; int16 _configuration
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _configuration
       (write-word _configuration s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _configuration
     (setq _configuration (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass rsp_msgs::ReconfigResponse
  :super ros::object
  :slots (_success ))

(defmethod rsp_msgs::ReconfigResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass rsp_msgs::Reconfig
  :super ros::object
  :slots ())

(setf (get rsp_msgs::Reconfig :md5sum-) "fd27df16901bf0767f619a2a1147b980")
(setf (get rsp_msgs::Reconfig :datatype-) "rsp_msgs/Reconfig")
(setf (get rsp_msgs::Reconfig :request) rsp_msgs::ReconfigRequest)
(setf (get rsp_msgs::Reconfig :response) rsp_msgs::ReconfigResponse)

(defmethod rsp_msgs::ReconfigRequest
  (:response () (instance rsp_msgs::ReconfigResponse :init)))

(setf (get rsp_msgs::ReconfigRequest :md5sum-) "fd27df16901bf0767f619a2a1147b980")
(setf (get rsp_msgs::ReconfigRequest :datatype-) "rsp_msgs/ReconfigRequest")
(setf (get rsp_msgs::ReconfigRequest :definition-)
      "int16 configuration
---
bool success

")

(setf (get rsp_msgs::ReconfigResponse :md5sum-) "fd27df16901bf0767f619a2a1147b980")
(setf (get rsp_msgs::ReconfigResponse :datatype-) "rsp_msgs/ReconfigResponse")
(setf (get rsp_msgs::ReconfigResponse :definition-)
      "int16 configuration
---
bool success

")



(provide :rsp_msgs/Reconfig "fd27df16901bf0767f619a2a1147b980")


