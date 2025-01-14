class Notification:
    def send(self, message):
        raise NotImplementedError("Subclasses must implement this method")


class EmailNotification(Notification):
    def send(self, message):
        print(f"Sending Email: {message}")


class SMSNotification(Notification):
    def send(self, message):
        print(f"Sending SMS: {message}")

class PushNotification(Notification):
    def send(self, message):
        print(f"Sending Push Notification: {message}")



def notify_employee(notification, message):
    notification.send(message)


if __name__ == '__main__':
    message1 = "New Policy Announcement"
    message2 = "Event Reminder: Office Party Tomorrow"
    message3 = "System Alert: Server Maintenance"

    
    email = EmailNotification()
    sms = SMSNotification()
    push = PushNotification()

    print("HR Notification:")
    notify_employee(email, message1)

    print("Events Team Notification:")
    notify_employee(sms, message2)

    print("IT Notification:")
    notify_employee(push, message3)
