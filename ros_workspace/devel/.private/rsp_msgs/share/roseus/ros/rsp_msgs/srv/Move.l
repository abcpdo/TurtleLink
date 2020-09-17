;; Auto-generated. Do not edit!


(when (boundp 'rsp_msgs::Move)
  (if (not (find-package "RSP_MSGS"))
    (make-package "RSP_MSGS"))
  (shadow 'Move (find-package "RSP_MSGS")))
(unless (find-package "RSP_MSGS::MOVE")
  (make-package "RSP_MSGS::MOVE"))
(unless (find-package "RSP_MSGS::MOVEREQUEST")
  (make-package "RSP_MSGS::MOVEREQUEST"))
(unless (find-package "RSP_MSGS::MOVERESPONSE")
  (make-package "RSP_MSGS::MOVERESPONSE"))

(in-package "ROS")





(defclass rsp_msgs::MoveRequest
  :super ros::object
  :slots (_name _x _y _theta ))

(defmethod rsp_msgs::MoveRequest
  (:init
   (&key
    ((:name __name) "")
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:theta __theta) 0.0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _theta (float __theta))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:theta
   (&optional __theta)
   (if __theta (setq _theta __theta)) _theta)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _theta
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _theta
       (sys::poke _theta (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _theta
     (setq _theta (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass rsp_msgs::MoveResponse
  :super ros::object
  :slots (_success ))

(defmethod rsp_msgs::MoveResponse
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

(defclass rsp_msgs::Move
  :super ros::object
  :slots ())

(setf (get rsp_msgs::Move :md5sum-) "57a5ee7dbb9c528e1eb4e1fa13982317")
(setf (get rsp_msgs::Move :datatype-) "rsp_msgs/Move")
(setf (get rsp_msgs::Move :request) rsp_msgs::MoveRequest)
(setf (get rsp_msgs::Move :response) rsp_msgs::MoveResponse)

(defmethod rsp_msgs::MoveRequest
  (:response () (instance rsp_msgs::MoveResponse :init)))

(setf (get rsp_msgs::MoveRequest :md5sum-) "57a5ee7dbb9c528e1eb4e1fa13982317")
(setf (get rsp_msgs::MoveRequest :datatype-) "rsp_msgs/MoveRequest")
(setf (get rsp_msgs::MoveRequest :definition-)
      "string name
float32 x
float32 y
float32 theta
---
bool success
")

(setf (get rsp_msgs::MoveResponse :md5sum-) "57a5ee7dbb9c528e1eb4e1fa13982317")
(setf (get rsp_msgs::MoveResponse :datatype-) "rsp_msgs/MoveResponse")
(setf (get rsp_msgs::MoveResponse :definition-)
      "string name
float32 x
float32 y
float32 theta
---
bool success
")



(provide :rsp_msgs/Move "57a5ee7dbb9c528e1eb4e1fa13982317")


