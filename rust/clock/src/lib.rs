pub struct Clock;

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let total: i32 = (hours * 60) + minutes;
        total %= 1440;
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        todo!("Add {minutes} minutes to existing Clock time");
    }
}
