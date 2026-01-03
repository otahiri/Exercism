pub struct Clock;

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let temp: i32 = minutes + (hours * 60);
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        todo!("Add {minutes} minutes to existing Clock time");
    }
}
