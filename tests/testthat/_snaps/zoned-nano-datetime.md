# printing zoned-nano-datetime

    <civil_nano_datetime<UTC>[1]>
    [1] "2019-05-01T00:00:00.000000005+00:00"

---

    <civil_nano_datetime<America/New_York>[1]>
    [1] "2019-05-01T00:00:00.000000005-04:00"

---

    <civil_nano_datetime<UTC>[3]>
    [1] "2019-05-01T00:00:03.000000005+00:00" "2020-05-01T00:00:04.000000006+00:00"
    [3] NA                                   

# printing zoned-nano-datetime - ambiguous time

    <civil_nano_datetime<America/New_York>[2]>
    [1] "1970-10-25T01:30:00.000000005-04:00" "1970-10-25T01:30:00.000000005-05:00"

# printing zoned-nano-datetime - extended format

    [1] "1970-10-25T01:30:00.000005000-04:00"

---

    [1] "1970-10-25T01:30:00.000005000-04:00[America/New_York]"

---

    [1] "1970-10-25T01:30:00.000005000-04:00[EDT]"
