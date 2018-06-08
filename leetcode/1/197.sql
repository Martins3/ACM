select id from  Weather W1
    where exists (
        select id from Weather W2
            where W2.RecordDate = SUBDATE(date, 1)
            and W2.Temperature <  W1.Temperature
    )
